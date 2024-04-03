#include <raylib-cpp.hpp>
#include <memory>
#include <iostream>

enum LoopOptions { LONone = 1, LOMain = 2, LOSound = 4, LOUi = 8};

class IDynamic {
public:
    IDynamic() = default;
    virtual ~IDynamic() = default;

    virtual void mainLoop() = 0;

    virtual void soundLoop() = 0;

    virtual void uiLoad() = 0;

private:
    // set flags according to the wanted function calls
    LoopOptions functionOptionCalls;
};

extern "C" {
IDynamic* Initialize();}