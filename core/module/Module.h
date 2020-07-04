#ifndef SERIALPLOTTER_MODULE_H
#define SERIALPLOTTER_MODULE_H

#include <memory>

class Module {
public:
    virtual void start() = 0;
    virtual void stop() = 0;

    virtual void update(size_t tick) = 0;
    virtual void render() = 0;
};

typedef std::unique_ptr<Module> ModulePtr;

#endif //SERIALPLOTTER_MODULE_H
