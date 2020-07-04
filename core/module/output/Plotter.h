#ifndef SERIALPLOTTER_PLOTTER_H
#define SERIALPLOTTER_PLOTTER_H

#include <vector>
#include <random>

#include "../Module.h"

#include "../../helper/widgets/Plot.h"

class Plotter : public Module {
private:
    Plot plot{};

    PlotChannel values{};

    std::mt19937 random_engine{};

    std::uniform_real_distribution<float> generator{0.0f, 100.0f};
public:
    void start() override;

    void stop() override;

    void update(size_t tick) override;

    void render() override;

    void clear_values();

    void put_value(float value);
};

typedef std::unique_ptr<Plotter> PlotterPtr;

#endif //SERIALPLOTTER_PLOTTER_H
