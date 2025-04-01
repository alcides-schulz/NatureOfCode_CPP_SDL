#include "Example_05_14_Sketch.h"

namespace nature_of_code_chapter_05_example_14
{
    bool Sketch::Setup(void)
    {
        InitSinCos();
        return true;
    }

    bool Sketch::Draw(void)
    {
        Background(255);

        auto radius = 50 + 50 * _sin_table[FrameCount() % kPeriod];
        SDL_SetRenderDrawColor(Renderer(), 0, 0, 0, 255);
        Stroke(1);
        for (int i = 0; i < 360; i += 5) {
            auto theta = (int)(i * kInvPrecision) % kPeriod;
            Rect((int)(Width() / 2 + radius * _cos_table[theta]), (int)(Height() / 2 + radius * _sin_table[theta]), 2, 2);
        }

        return true;
    }

    void Sketch::InitSinCos(void)
    {
        _sin_table.reserve(kPeriod);
        _cos_table.reserve(kPeriod);
        for (int i = 0; i < kPeriod; i++) {
            _sin_table[i] = sinf(i * kDegToRad * kPrecision);
            _cos_table[i] = cosf(i * kDegToRad * kPrecision);
        }
    }
}

// END
