#include "IDynamic.h"

class test : public IDynamic {
public:
    test() = default;
    void mainLoop() override;
    void soundLoop() override;
    void uiLoad() override;
};

