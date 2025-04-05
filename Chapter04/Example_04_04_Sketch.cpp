#include "Example_04_04_Sketch.h"

namespace nature_of_code_chapter_04_example_04
{
    bool Sketch::Setup(void)
    {
        cout << "Left-Click to add particle system and Right-Click to remove particle system." << endl;
        return true;
    }
    
    bool Sketch::Draw(void)
    {
        Background(255);
        if (IsMouseButtonClicked(kMouseLeftButton)) {
            _emitters.push_back(new Emitter(MousePosition().x, MousePosition().y));
        }
        if (IsMouseButtonClicked(kMouseRightButton) && _emitters.size() > 0) {
            _emitters.erase(_emitters.begin());
        }
        for each (auto emitter in _emitters)
        {
            emitter->AddParticle();
            emitter->Run(this);
        }
        return true;
    }
    
}

// END
