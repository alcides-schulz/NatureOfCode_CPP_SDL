#include "Example_05_04_FlowField.h"

namespace nature_of_code_chapter_05_example_04
{
    void FlowField::Init(void)
    {
        auto perlin_noise = new PerlinNoise2D((int)Utils::Random(10000));
        float xoff = 0;
        for (int i = 0; i < cols_; i++) {
            float yoff = 0;
            for (int j = 0; j < rows_; j++) {
                auto noise = perlin_noise->Noise(xoff, yoff);
                auto angle = Utils::Map(noise, 0, 1, 0, M_PI * 2);
                field_[i][j] = PVector::FromAngle(angle);
                yoff += 0.1f;
            }
            xoff += 0.1f;
        }
        delete perlin_noise;
    }

    void FlowField::Show(SDL_Framework *framework)
    {
        framework->Stroke(kColorBlack);
        for (int i = 0; i < cols_; i++) {
            for (int j = 0; j < rows_; j++) {
                auto w = framework->Width() / cols_;
                auto h = framework->Height() / rows_;
                auto v = field_[i][j].Clone();
                v.SetMag(w * 0.5f);
                auto x = i * w + w / 2;
                auto y = j * h + h / 2;
                framework->Line(x, y, (int)(x + v.x), (int)(y + v.y));
            }
        }
    }

    PVector FlowField::Lookup(PVector position)
    {
        auto column = Utils::Constrain((int)std::floor(position.x / resolution_), 0, cols_ - 1);
        auto row = Utils::Constrain((int)std::floor(position.y / resolution_), 0, rows_ - 1);
        return field_[column][row].Clone();
    }
}
 
// END
