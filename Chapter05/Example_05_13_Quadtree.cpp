#include "Example_05_13_Quadtree.h"

namespace nature_of_code_chapter_05_example_13
{

    QuadTree::QuadTree(P5SDL *p5sdl, Rectangle boundary, int capacity)
    {
        _p5sdl = p5sdl;
        _boundary = boundary;
        _capacity = capacity;
        _divided = false;
        _northeast = nullptr;
        _northwest = nullptr;
        _southeast = nullptr;
        _southwest = nullptr;
    }

    void QuadTree::Subdivide(void)
    {
        auto x = _boundary.x;
        auto y = _boundary.y;
        auto w = _boundary.w;
        auto h = _boundary.h;
        auto ne = Rectangle(x + w / 2, y - h / 2, w / 2, h / 2);
        _northeast = new QuadTree(_p5sdl, ne, _capacity);
        auto nw = Rectangle(x - w / 2, y - h / 2, w / 2, h / 2);
        _northwest = new QuadTree(_p5sdl, nw, _capacity);
        auto se = Rectangle(x + w / 2, y + h / 2, w / 2, h / 2);
        _southeast = new QuadTree(_p5sdl, se, _capacity);
        auto sw = Rectangle(x - w / 2, y + h / 2, w / 2, h / 2);
        _southwest = new QuadTree(_p5sdl, sw, _capacity);
        _divided = true;
    }

    bool QuadTree::Insert(Point point)
    {
        if (!_boundary.Contains(point))
            return false;
        if (_points.size() < _capacity) {
            _points.push_back(point);
            return true;
        }
        if (!_divided)
            Subdivide();
        if (_northeast->Insert(point))
            return true;
        if (_northwest->Insert(point))
            return true;
        if (_southeast->Insert(point))
            return true;
        if (_southwest->Insert(point))
            return true;
        return false;
    }

    void QuadTree::Query(Rectangle &range, vector<Point> &found)
    {
        if (!_boundary.Intersects(range)) {
            return;
        }
        for (auto point : _points) {
            if (range.Contains(point)) {
                found.push_back(point);
            }
        }
        if (_divided) {
            _northeast->Query(range, found);
            _northwest->Query(range, found);
            _southeast->Query(range, found);
            _southwest->Query(range, found);
        }
    }

    void QuadTree::Show(void)
    {
        _p5sdl->Stroke(0);
        _p5sdl->Fill(255);
        _p5sdl->StrokeWeight(1);
        _p5sdl->RectMode(kRectCenter);
        _p5sdl->Rect(_boundary.x, _boundary.y, _boundary.w * 2, _boundary.h * 2);
        for (auto point : _points) {
            _p5sdl->StrokeWeight(1);
            _p5sdl->Stroke(0);
            SDL_RenderDrawPoint(_p5sdl->Renderer(), point.x, point.y);
        }
        if (_divided) {
            _northeast->Show();
            _northwest->Show();
            _southeast->Show();
            _southwest->Show();
        }
    }

    void QuadTree::Cleanup()
    {
        if (_divided) {
            _northeast->Cleanup();
            _northwest->Cleanup();
            _southeast->Cleanup();
            _southwest->Cleanup();
            delete _northeast;
            delete _northwest;
            delete _southeast;
            delete _southwest;
        }
    }
}

// END
