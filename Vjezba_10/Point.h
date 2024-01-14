#pragma once

#include <string>
#include <iterator>


class Point {

public:
    double x;
    double y;

    Point() {};
    Point(const Point &p) {};
    Point(double a, double b) { this->x = a; this->y = b; }
};

void processWordsFile(const std::string& filename, const std::string& targetWord, const std::string& substringToRemove);

double distanceFromOrigin(const Point& p);

void processPointsFile(const std::string& filename, double circleRadius);















