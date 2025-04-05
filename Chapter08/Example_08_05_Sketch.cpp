#include "Example_08_05_Sketch.h"

namespace nature_of_code_chapter_08_example_05
{
    bool Sketch::Setup(void)
    {
        auto start = Vector(0, 200);
        auto end = Vector(Width(), 200);
        _segments.push_back(new KochLine(this, start, end));
        for (int i = 0; i < 5; i++)
            Generate();
        return true;
    }

    bool Sketch::Draw(void)
    {
        Background(255);

        for (auto segment : _segments)
            segment->Show();
        NoLoop();

        return true;
    }

    void Sketch::Generate(void)
    {
        vector<KochLine *> next;
        for (auto segment : _segments) {
            vector<Vector> vectors = segment->KochPoints();
            next.push_back(new KochLine(this, vectors[0], vectors[1]));
            next.push_back(new KochLine(this, vectors[1], vectors[2]));
            next.push_back(new KochLine(this, vectors[2], vectors[3]));
            next.push_back(new KochLine(this, vectors[3], vectors[4]));
        }
        _segments = next;

    }

    void Sketch::Cleanup(void)
    {
        for (auto segment : _segments)
            delete segment;
        _segments.clear();
    }
}

// END
