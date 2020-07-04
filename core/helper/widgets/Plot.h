#ifndef SERIALPLOTTER_PLOT_H
#define SERIALPLOTTER_PLOT_H

#include <vector>
#include <memory>
#include <algorithm>

#include "PlotType.h"

typedef std::vector<int> PlotValues;
typedef std::shared_ptr<PlotValues> PlotChannel;
typedef std::vector<PlotChannel> PlotChannels;

class Plot {
private:
    PlotType plot_type{PlotType::Bars};

    PlotChannels channels{};
public:
    float zoom{1.0f};

    std::vector<size_t> cursors{};
public:
    void render();

    PlotChannel add_channel();

    void remove_channel(const PlotChannel& channel);
};

#endif //SERIALPLOTTER_PLOT_H
