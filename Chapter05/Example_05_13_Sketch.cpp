#include "Example_05_13_Sketch.h"

namespace nature_of_code_chapter_05_example_13
{
    bool Sketch::Setup(void)
    {
        auto boundary = Rectangle(Width() / 2, Height() / 2, Width(), Height());
        _quadtree = new QuadTree(this, boundary, 8);
        for (int i = 0; i < 1000; i++) {
            auto x = (int)Utils::RandomGaussian(Width() / 2.0f, Width() / 8.0f);
            auto y = (int)Utils::RandomGaussian(Height() / 2.0f, Height() / 8.0f);
            auto point = Point(x, y);
            _quadtree->Insert(point);
        }
        return true;
    }

    bool Sketch::Draw(void)
    {
        Background(255);

        _quadtree->Show();

        RectMode(kRectCenter);
        auto range = Rectangle(MousePosition().x, MousePosition().y, 50, 50);
        if (range.x < Width() && range.y < Height()) {
            StrokeWeight(2);
            Stroke({ 255, 50, 50, 255 });
            Fill({ 255, 50, 50, 50 });
            Rect(range.x, range.y, range.w * 2, range.h * 2);
            vector<Point> points;
            _quadtree->Query(range, points);
            for (auto point : points) {
                StrokeWeight(3);
                Stroke({ 50, 50, 50, 255 });
                SDL_RenderDrawPoint(Renderer(), point.x, point.y);
            }
        }

        return true;
    }

    void Sketch::Cleanup(void)
    {
        _quadtree->Cleanup();
        delete _quadtree;
    }
}

// END
