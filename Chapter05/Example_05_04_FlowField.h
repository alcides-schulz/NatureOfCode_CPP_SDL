#ifndef EXAMPLE_05_04_FLOWFIELD_H
#define EXAMPLE_05_04_FLOWFIELD_H

#include "../Common/SDL_Framework.h"
#include "../Common/PVector.h"
#include "../Common/Utils.h"
#include "../Common/PerlinNoise2D.h"

namespace nature_of_code_chapter_05_example_04
{
    class FlowField
    {
    public:
        FlowField(int width, int height, int resolution)
        {
            resolution_ = resolution;
            cols_ = width / resolution_;
            rows_ = height / resolution_;
            field_ = std::vector<std::vector<PVector>>(cols_, std::vector<PVector>(rows_));
            Init();
        };
        void Init(void);
        void Show(SDL_Framework *framework);
        PVector Lookup(PVector position);
    private:
        int     resolution_;
        int     rows_;
        int     cols_;
        std::vector<std::vector<PVector>> field_;
    };
}

#endif
