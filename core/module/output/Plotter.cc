#include "Plotter.h"

#include <imgui.h>

void Plotter::start() {
    this->values = this->plot.add_channel();
    auto a = this->plot.add_channel();
    a->emplace_back(5);
    a->emplace_back(10);
}

void Plotter::stop() {

}

void Plotter::update(size_t tick) {

}

void Plotter::render() {
    ImGui::Begin("Plotter");

    if (ImGui::Button("Add value")) {
        this->put_value(this->generator(this->random_engine));
    }

    ImGui::SameLine();

    ImGui::SliderFloat("Zoom", &this->plot.zoom, 0.01f, 20.0f, "%.2f");

    this->plot.render();

    ImGui::End();
}

void Plotter::clear_values() {
    this->values->clear();
}

void Plotter::put_value(float value) {
    this->values->emplace_back(value);
}
