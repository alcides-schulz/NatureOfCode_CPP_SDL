#include "Example_05_04_FlowField.h"

namespace nature_of_code_chapter_05_example_04
{
    void FlowField::Init(void)
    {
        auto perlin_noise = new PerlinNoise2D((int)Utils::Random(10000));
        float xoff = 0;
        for (int i = 0; i < _cols; i++) {
            float yoff = 0;
            for (int j = 0; j < _rows; j++) {
                auto noise = perlin_noise->Noise(xoff, yoff);
                auto angle = Utils::Map(noise, 0, 1, 0, M_PI * 2);
                _field[i][j] = Vector::FromAngle(angle);
                yoff += 0.1f;
            }
            xoff += 0.1f;
        }
        delete perlin_noise;
    }

    void FlowField::Show(P5SDL *p5sdl)
    {
        p5sdl->Stroke(kColorBlack);
        for (int i = 0; i < _cols; i++) {
            for (int j = 0; j < _rows; j++) {
                auto w = p5sdl->Width() / _cols;
                auto h = p5sdl->Height() / _rows;
                auto v = _field[i][j].Clone();
                v.SetMag(w * 0.5f);
                auto x = i * w + w / 2;
                auto y = j * h + h / 2;
                p5sdl->Line(x, y, (int)(x + v.x), (int)(y + v.y));
            }
        }
    }

    Vector FlowField::Lookup(Vector position)
    {
        auto column = Utils::Constrain((int)std::floor(position.x / _resolution), 0, _cols - 1);
        auto row = Utils::Constrain((int)std::floor(position.y / _resolution), 0, _rows - 1);
        return _field[column][row].Clone();
    }
}
 
// END
