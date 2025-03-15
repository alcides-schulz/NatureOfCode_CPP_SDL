#ifndef GENERATE_EXAMPLE_INITIAL_CODE_H
#define GENERATE_EXAMPLE_INITIAL_CODE_H

#include "../Common/SDL_Framework.h"

class GenerateExampleInitialCode : public SDL_Framework
{
public:
    GenerateExampleInitialCode() : SDL_Framework("Generate Example Initial Code", -1, -1, 640, 240, 0) {}
    bool Setup(void) override;
    bool Draw() override { return false; };
};

#endif

