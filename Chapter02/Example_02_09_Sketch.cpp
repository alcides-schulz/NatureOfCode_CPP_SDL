#include "Example_02_09_Sketch.h"
#include "../Common/Utils.h"
namespace nature_of_code_chapter_02_example_09
{
    
    bool Sketch::Setup()
    {
        for (int i = 0; i < std::size(_body); i++) {
            auto x = Utils::Random((float)Width());
            auto y = Utils::Random((float)Height());
            auto m = (int)Utils::Random(1, 4);
            _body[i] = new Body(Vector(x, y), m);
        }
    
        return true;
    }
    
    bool Sketch::Draw()
    {
        Background(255);
    
        for (int i = 0; i < std::size(_body); i++) {
            for (int j = 0; j < std::size(_body); j++) {
                if (i == j)
                    continue;
                _body[i]->Attract(_body[j]);
            }
        }
        for (int i = 0; i < std::size(_body); i++) {
            _body[i]->Update();
            _body[i]->Show(this);
        }
    
        return true;
    }
    
}

// END
