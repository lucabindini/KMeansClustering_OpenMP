//
// Created by Benelli, Bindini on 18/01/2021.
//

#include "Point.h"

Point::Point(std::vector<float> coordinates) {
    this->coordinates = coordinates;
}

float Point::distanceFrom(const Point p) const {
    float sum = 0;
    for (int i = 0; i < coordinates.size(); i++)
        sum += pow((coordinates.at(i) - p.getCoordinates().at(i)), 2);
    return sqrt(sum);
}

bool Point::findNearest(std::vector<Point> points) {
    int minimum = 0;
    float distance = distanceFrom(points.at(0));
    float currDistance;
    bool hasChanged = false;
    for (int i = 1; i < points.size(); i++) {
        if ((currDistance = distanceFrom(points.at(i))) < distance) {
            distance = currDistance;
            minimum = i;
        }
    }
    if(minimum != centroidID)
        hasChanged = true;
    centroidID = minimum;
    return hasChanged;
}

const std::vector<float> &Point::getCoordinates() const {
    return coordinates;
}

int Point::getCentroidId() const {
    return centroidID;
}

Point::Point(int dimension) {
    std::vector<float> coordinates = std::vector<float>();
    for (int i = 0; i < dimension; i++)
        coordinates.push_back(0);
    this->coordinates = coordinates;
}

Point &Point::operator+=(const Point &rhs) {
    for (int i = 0; i < coordinates.size(); i++) {
        coordinates.at(i) += rhs.getCoordinates().at(i);
    }
    return *this;
}

Point &Point::operator/=(int num) {
    for (int i = 0; i < coordinates.size(); i++) {
        coordinates.at(i) /= num;
    }
    return *this;
}