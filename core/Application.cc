#include "Application.h"

unsigned int Application::run(const StringVector& start_parameters) {
    std::cout << "Starting application" << std::endl;

    if (!this->renderer->create()) {
        std::cout << "Failed to create window and renderer" << std::endl;
        return 1;
    }

    std::cout << "Initializing modules" << std::endl;

    this->plotter->start();

    std::cout << "Starting update thread" << std::endl;

    this->update_thread = std::thread{[&]() {
        size_t tick{0};
        while(this->running) {
            this->plotter->update(tick);
            tick++;
        }
    }};

    std::cout << "Ready" << std::endl;

    while (this->running) {
        this->running = !this->renderer->should_close();
        this->renderer->begin_frame();

        this->plotter->render();

        this->renderer->end_frame();
    }

    std::cout << "Stopping" << std::endl;

    this->update_thread.join();

    std::cout << "Stopping modules" << std::endl;

    this->plotter->stop();

    std::cout << "Stopping application" << std::endl;
    this->renderer->destroy();
    return 0;
}
