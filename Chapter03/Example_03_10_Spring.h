#ifndef EXAMPLE_03_10_SPRING_H
#define EXAMPLE_03_10_SPRING_H

#include "../Common/SDL_Framework.h"
#include "../Common/PVector.h"
#include "Example_03_10_Bob.h"

namespace nature_of_code_chapter_03_example_10
{
    class Spring
    {
    public:
        Spring(PVector anchor, float length) : anchor_(anchor), rest_length_(length)
        {
            k_ = 0.2f;
        };
        void Connect(Bob      *bob);
        void ConstrainLength(Bob      *bob, float min_length, float max_length);
        void Show(SDL_Framework *framework);
        void ShowLine(SDL_Framework *framework, Bob      *bob);
    private:
        PVector anchor_;
        float   rest_length_;
        float   k_;
    };
}

#endif
