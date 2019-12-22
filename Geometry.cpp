#include "Geometry.h"
void cgal_function()
{
    std::array<Point_2,5> po = {Point_2(0,0),Point_2(10,0),Point_2(10,10),Point_2(6,5),Point_2(4,1) };
    std::array<Point_2,5> result;
    
    std::unique_ptr<Point_2> ptr;
    ptr= std::make_unique<Point_2>(Cgal::convex_hull_2)
    
}
