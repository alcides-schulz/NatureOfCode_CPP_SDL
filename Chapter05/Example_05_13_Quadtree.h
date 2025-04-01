#ifndef EXAMPLE_05_13_QUADTREE_H
#define EXAMPLE_05_13_QUADTREE_H

#include "../Common/P5SDL.h"
#include "../Common/Vector.h"
#include "../Common/Utils.h"

namespace nature_of_code_chapter_05_example_13
{
    class Point
    {
    public:
        int x;
        int y;
        Point(int x, int y) : x(x), y(y) {};
    };

    class Rectangle 
    {
    public:
        int x;
        int y;
        int w;
        int h;
        Rectangle(void) {};
        Rectangle(int x, int y, int w, int h) : x(x), y(y), w(w), h(h) {};
        bool Contains(Point point)
        {
            return point.x >= x - w && 
                   point.x < x + w && 
                   point.y >= y - h && 
                   point.y < y + h;
        };
        bool Intersects(Rectangle range)
        {
            return !(range.x - range.w > x + w ||
                     range.x + range.w < x - w ||
                     range.y - range.h > y + h ||
                     range.y + range.h < y - h);
        };
    };

    class QuadTree
    {
    public:
        QuadTree(P5SDL *p5sdl, Rectangle boundary, int capacity);
        void Subdivide(void);
        bool Insert(Point point);
        void Query(Rectangle &range, vector<Point> &found);
        void Show(void);
        void Cleanup(void);
    private:
        P5SDL           *_p5sdl;
        Rectangle       _boundary;
        int             _capacity;
        vector<Point>   _points;
        bool            _divided;
        QuadTree        *_northeast;
        QuadTree        *_northwest;
        QuadTree        *_southeast;
        QuadTree        *_southwest;
    };
}

#endif
