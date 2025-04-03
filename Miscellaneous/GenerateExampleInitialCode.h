#ifndef GENERATE_EXAMPLE_INITIAL_CODE_H
#define GENERATE_EXAMPLE_INITIAL_CODE_H

#include "../Common/P5SDL.h"

#define CHAPTER "07"
#define EXAMPLE "01"
#define DESC "Wolfram Elementary Cellular Automata"

#define TITLE "Gen Initial Code: " CHAPTER "." EXAMPLE ": '" DESC "'"

class GenerateExampleInitialCode : public P5SDL
{
public:
    GenerateExampleInitialCode() : P5SDL(TITLE, -1, -1, 640, 240, 0) {}
    bool Setup(void) override;
    bool Draw() override { return false; };
};

#endif

