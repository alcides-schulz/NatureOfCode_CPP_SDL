#include "Example_2_9.h"
#include "../Common/Utils.h"

bool Example_2_9::Setup()
{
    for (int i = 0; i < std::size(body_); i++) {
        auto x = Utils::Random((float)Width());
        auto y = Utils::Random((float)Height());
        auto m = (int)Utils::Random(1, 4);
        body_[i] = new Body_2_9(PVector(x, y), m);
    }

    return true;
}

bool Example_2_9::Draw()
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

// END