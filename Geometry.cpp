#include "Geometry.h"
using namespace std;
void cgal_function()
{
    std::array<Point_2,5> po = {Point_2(0,0),Point_2(10,0),Point_2(10,10),Point_2(6,5),Point_2(4,1) };
    std::array<Point_2,5> result;
    
    std::unique_ptr<Point_2> ptr;
    CGAL::convex_hull_2(po.begin(),po.end(),result.begin());
    for(int i=0;i<5;i++)
    {
        cout<< "result" <<result[i]<<std::endl;
    }
}
