//
// Created by Benelli, Bindini on 18/01/2021.
//

#ifndef KMEANSCLUSTERING_OPENMP_POINT_H
#define KMEANSCLUSTERING_OPENMP_POINT_H

#include <iostream>
#include <vector>
#include <cmath>


class Point {
public:
    Point(std::vector<float> coordinates);

    Point(int dimension);

    float distanceFrom(const Point p) const;

    bool findNearest(std::vector<Point> points);

    const std::vector<float> &getCoordinates() const;

    int getCentroidId() const;

    Point &operator+=(const Point &rhs);

    Point &operator/=(int num);

private:
    std::vector<float> coordinates;
    int centroidID;

};


#endif //KMEANSCLUSTERING_OPENMP_POINT_H
