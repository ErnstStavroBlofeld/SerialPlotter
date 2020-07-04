#include "Plot.h"

#include <fmt/format.h>

#include <imgui.h>
#include <imgui_internal.h>

void Plot::render() {
    ImVec2 size = ImGui::GetContentRegionAvail();
    ImGui::BeginChild("Plot", size, false, ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_AlwaysHorizontalScrollbar |
                                           ImGuiWindowFlags_NoScrollWithMouse);

    static auto vector_getter = [](void *vector_ptr, int index) {
        const auto &vector = *reinterpret_cast<PlotValues *>(vector_ptr);
        return static_cast<float>((index < vector.size()) ? vector[index] : 0);
    };

    ImVec2 plot_size = ImGui::GetContentRegionAvail();
    size_t channel_height = static_cast<size_t>(plot_size.y - 10) / this->channels.size();

    for (size_t channel_index = 0; channel_index < this->channels.size(); channel_index++) {
        void (*plot_function)(const char *, float(*)(void *, int), void *, int, int, const char *, float, float, ImVec2)
            = nullptr;

        switch (this->plot_type) {
            case PlotType::Bars:
                plot_function = &ImGui::PlotHistogram;
                break;

            case PlotType::Lines:
                plot_function = &ImGui::PlotLines;
                break;
        }

        plot_function(fmt::format("##{}", channel_index + 1).c_str(),
                      vector_getter,
                      reinterpret_cast<void *>(this->channels[channel_index].get()),
                      this->channels[channel_index]->size(),
                      0,
                      nullptr,
                      0,
                      MAXFLOAT,
                      ImVec2(size.x * zoom, channel_height));
    }

    ImGui::EndChild();
}

PlotChannel Plot::add_channel() {
    auto plot_channel = std::make_shared<PlotValues>();
    this->channels.emplace_back(plot_channel);
    return plot_channel;
}

void Plot::remove_channel(const PlotChannel &channel) {
    auto iterator = std::find(std::begin(this->channels),
                              std::end(this->channels),
                              channel);

    if (iterator != std::end(this->channels))
        this->channels.erase(iterator);
}
