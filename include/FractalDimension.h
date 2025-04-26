#pragma once
#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <algorithm>
#include <unordered_set>
#include <random>
#include <set>
using namespace std;

//
struct Point3D
{
    const double x, y, z;
    Point3D(double x_, double y_, double z_) : x(x_), y(y_), z(z_) {}
};


Point3D computeOrtoCenter(const vector<Point3D>& points);
double computeLeights(const vector<Point3D>& points);


Point3D computeCenter(const vector<Point3D>& points);
double computeMaxDistance(const vector<Point3D>& points, const Point3D& center);


double computeFractalDimensionGeometry(const vector<Point3D>& points, int numScales);


double computeFractalDimensionMass(const vector<Point3D>& points, int numScales);


vector<double> globalFunction(const vector<Point3D>& points, double epsilon);
