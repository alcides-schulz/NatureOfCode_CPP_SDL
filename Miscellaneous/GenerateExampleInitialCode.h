#ifndef GENERATE_EXAMPLE_INITIAL_CODE_H
#define GENERATE_EXAMPLE_INITIAL_CODE_H

#include "../Common/P5SDL.h"

#define GEN_CHAPTER "09"
#define GEN_EXAMPLE "05"
#define GEN_DESC "An Evolving Ecosystem"
#define GEN_LIST {"Bloop", "DNA", "Food", "World"}

#define GEN_TITLE "Gen Initial Code: " GEN_CHAPTER "." GEN_EXAMPLE ": '" GEN_DESC "'"

class GenerateExampleInitialCode : public P5SDL
{
public:
    GenerateExampleInitialCode() : P5SDL(GEN_TITLE, -1, -1, 640, 240, 0) {}
    bool Setup(void) override;
    bool Draw() override { return false; };
private:
    void GenerateSketchClass();
    void GenerateClass(string class_name);
};

#endif

