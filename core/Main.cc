#include "Application.h"

int main(int argc, char** argv) {
    StringVector start_parameters{};

    for (std::size_t i = 0; i < argc; i++)
        start_parameters.emplace_back(std::string{argv[i]});

    return static_cast<int>(Application{}.run(start_parameters));
}
