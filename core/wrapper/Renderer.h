#ifndef SERIALPLOTTER_RENDERER_H
#define SERIALPLOTTER_RENDERER_H

#include <iostream>
#include <memory>

struct GLFWwindow;

class Renderer {
private:
    GLFWwindow* native_window{nullptr};

    size_t width{1280}, height{720};
public:
    bool create();

    void destroy();

    void begin_frame();

    void end_frame();

    bool should_close() const;

    size_t get_width() const;

    size_t get_height() const;
};

typedef std::unique_ptr<Renderer> RendererPtr;

#endif //SERIALPLOTTER_RENDERER_H
