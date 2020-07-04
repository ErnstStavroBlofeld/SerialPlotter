#ifndef SERIALPLOTTER_APPLICATION_H
#define SERIALPLOTTER_APPLICATION_H

#include <iostream>
#include <vector>
#include <memory>
#include <string>
#include <thread>

#include "wrapper/Renderer.h"

#include "module/output/Plotter.h"

typedef std::vector<std::string> StringVector;

class Application {
private:
    RendererPtr renderer = std::make_unique<Renderer>();

    PlotterPtr plotter = std::make_unique<Plotter>();

    std::thread update_thread{};

    bool running{true};
public:
    unsigned int run(const StringVector& start_parameters);
};

#endif //SERIALPLOTTER_APPLICATION_H
