#ifndef GEOMETRY_H_INCLUDED
#define GEOMETRY_H_INCLUDED

#include <CGAL/Simple_cartesian.h>
#include <CGAL/Exact_predicates_inexact_constructions_kernel.h>
#include <CGAL/convex_hull_2.h>
#include <array>
#include <memory>
#include <iterator>
#include <iostream>
typedef CGAL::Simple_cartesian<double> Kernel;
//typedef Kernel::Point_2 Point_2;
//typedef Kernel::Segment_2 Segment_2;
typedef CGAL::Exact_predicates_inexact_constructions_kernel K;
typedef K::Point_2 Point_2;
void cgal_function();

#endif // GEOMETRY_H_INCLUDED
