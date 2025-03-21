#include "Example_02_09_Sketch.h"
#include "../Common/Utils.h"
namespace nature_of_code_chapter_02_example_09
{
    
    bool Sketch::Setup()
    {
        for (int i = 0; i < std::size(body_); i++) {
            auto x = Utils::Random((float)Width());
            auto y = Utils::Random((float)Height());
            auto m = (int)Utils::Random(1, 4);
            body_[i] = new Body(PVector(x, y), m);
        }
    
        return true;
    }
    
    bool Sketch::Draw()
    {
        ClearScreen();
    
        for (int i = 0; i < std::size(body_); i++) {
            for (int j = 0; j < std::size(body_); j++) {
                if (i == j)
                    continue;
                body_[i]->Attract(body_[j]);
            }
        }
        for (int i = 0; i < std::size(body_); i++) {
            body_[i]->Update();
            body_[i]->Show(this);
        }
    
        return true;
    }
    
}

// END
