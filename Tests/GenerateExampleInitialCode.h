#ifndef GENERATE_EXAMPLE_INITIAL_CODE_H
#define GENERATE_EXAMPLE_INITIAL_CODE_H

#include "../Common/P5SDL.h"

class GenerateExampleInitialCode : public P5SDL
{
public:
    GenerateExampleInitialCode() : P5SDL("Generate Example Initial Code", -1, -1, 640, 240, 0) {}
    bool Setup(void) override;
    bool Draw() override { return false; };
};

#endif

