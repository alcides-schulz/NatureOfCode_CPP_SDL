#include "Example_04_04_Sketch.h"

namespace nature_of_code_chapter_04_example_04
{
    bool Sketch::Setup(void)
    {
        cout << "Click to add particle system." << endl;
        return true;
    }
    
    bool Sketch::Draw(void)
    {
        Background(255);
        if (IsMouseButtonClicked(kMouseLeftButton)) {
            emitters_.push_back(new Emitter(MousePosition().x, MousePosition().y));
        }
        if (IsMouseButtonClicked(kMouseRightButton) && emitters_.size() > 0) {
            emitters_.erase(emitters_.begin());
        }
        for each (auto emitter in emitters_)
        {
            emitter->AddParticle();
            emitter->Run(this);
        }
        return true;
    }
    
}

// END
