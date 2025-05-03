#include "Example_09_05_World.h"

namespace nature_of_code_chapter_09_example_05
{
    World::World(P5SDL *p5sdl, int population_size)
    {
        _p5sdl = p5sdl;
        for (int i = 0; i < population_size; i++) {
            auto position = Vector(Utils::Random(p5sdl->Width()), Utils::Random(p5sdl->Height()));
            auto dna = new DNA();
            _bloops.push_back(new Bloop(p5sdl, position, dna));
        }
        _food = new Food(p5sdl, population_size);
    }

    void World::Run(void)
    {
        _food->Run();
        for (int i = (int)_bloops.size() - 1; i >= 0; i--) {
            auto bloop = _bloops[i];
            bloop->Run();
            bloop->Eat(_food);
            if (bloop->IsDead()) {
                _bloops.erase(_bloops.begin() + i);
                _food->Add(bloop->GetPosition());
                delete bloop;
            }
            else {
                //auto child = bloop->Reproduce();
                //if (child != nullptr)
                //    _bloops.push_back(child);
            }
        }
    }

    void World::Born(void)
    {
        auto position = Vector(_p5sdl->MousePosition().x, _p5sdl->MousePosition().y);
        auto dna = new DNA();
        _bloops.push_back(new Bloop(_p5sdl, position, dna));
    }
}

// END
