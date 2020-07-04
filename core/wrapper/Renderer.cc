#include "Renderer.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <imgui.h>
#include <imgui_impl_opengl3.h>
#include <imgui_impl_glfw.h>

bool Renderer::create() {
    std::cout << "Setting up window" << std::endl;

    glfwSetErrorCallback([](int error_code, const char *description) {
        std::cerr << "An GLFW error occurred (" << error_code << ") " << description << std::endl;
    });

    if (!glfwInit())
        return false;

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

    this->native_window = glfwCreateWindow(this->width, this->height, "SerialPlotter", nullptr, nullptr);
    if (!this->native_window)
        return false;

    std::cout << "Setting up graphics" << std::endl;

    glfwMakeContextCurrent(this->native_window);
    glfwSwapInterval(1);

    if (!gladLoadGL()) {
        std::cerr << "Failed to initialize GLAD" << std::endl;
        return false;
    }

    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO &io = ImGui::GetIO();
    static_cast<void>(io);

    io.Fonts->AddFontFromFileTTF("res/fonts/sans.ttf", 16.0f, nullptr, io.Fonts->GetGlyphRangesDefault());

    ImGui::StyleColorsDark();

    ImGui_ImplGlfw_InitForOpenGL(this->native_window, true);
    ImGui_ImplOpenGL3_Init();

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    return true;
}

void Renderer::destroy() {
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();

    glfwDestroyWindow(this->native_window);
    glfwTerminate();
}

void Renderer::begin_frame() {
    int int_width{0}, int_height{0};
    glfwGetFramebufferSize(this->native_window, &int_width, &int_height);
    this->width = static_cast<size_t>(int_width);
    this->height = static_cast<size_t>(int_height);

    glfwSwapBuffers(this->native_window);
    glfwPollEvents();

    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();
}

void Renderer::end_frame() {
    ImGui::Render();
    glClear(GL_COLOR_BUFFER_BIT);
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}

bool Renderer::should_close() const {
    return glfwWindowShouldClose(this->native_window);
}

size_t Renderer::get_width() const {
    return this->width;
}

size_t Renderer::get_height() const {
    return this->height;
}
