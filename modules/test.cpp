#include "test.h"

void test::mainLoop() { }

void test::soundLoop() { }

void test::uiLoad() { }

extern "C" {
IDynamic* InitializeTest() {
    return new test();
}
}