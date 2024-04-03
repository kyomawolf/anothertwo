#include "test.h"

void test::mainLoop() { }

void test::soundLoop() { }

void test::uiLoad() { }

extern "C" {
IDynamic* Initialize() {
    return new test();
}
}