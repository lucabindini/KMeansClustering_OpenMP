//
// Created by Benelli, Bindini on 25/01/2021.
//

#include <random>
#include "KMeans.h"

KMeans::KMeans(int k, int n, int dimension, int maxIter) {
    this->k = k;
    this->n = n;
    this->dimension = dimension;
    this->maxIter = maxIter;
    points = std::vector<Point>();
    centroids = std::vector<Point>();
    oldCentroids = std::vector<Point>();
    hasChanged = false;
    init();
}

void KMeans::init() {
    std::random_device rd;
    std::mt19937 gen(rd());
    for (int i = 0; i < n; i++) {
        std::vector<float> coordinates = std::vector<float>(dimension);
        for (int j = 0; j < dimension; j++) {
            coordinates[j] = std::generate_canonical<float, 10>(gen);
        }
        points.emplace_back(coordinates);
    }
    for (int i = 0; i < k; i++)
        centroids.push_back(points.at(i));
}

void KMeans::printAllPoints() {
    for (int i = 0; i < n; i++) {
        std::cout << "Point " << i << ": ";
        for (int j = 0; j < dimension; j++) {
            std::cout << points.at(i).getCoordinates().at(j) << " ";
        }
        std::cout << "- CentroidID: " << points.at(i).getCentroidId() << std::endl;
    }
    std::cout << std::endl;
}

void KMeans::printCentroids() {
    for (int i = 0; i < k; i++) {
        std::cout << "Centroid " << i << ": ";
        for (int j = 0; j < dimension; j++) {
            std::cout << centroids.at(i).getCoordinates().at(j) << " ";
        }
        std::cout << std::endl;
    }
}

void KMeans::assignCentroids() {
    hasChanged = false;
#pragma omp parallel for default(none) shared(hasChanged)
    for (Point p: points) {
        if (p.findNearest(centroids))
            hasChanged = true;
    }
//    if (hasChanged)
//        std::cout << "HAS CHANGED" << std::endl;
}

void KMeans::moveCentroids() {
#pragma omp parallel for default(none)
    for (int i = 0; i < k; i++) {
        moveCentroid(i);
    }
}

void KMeans::moveCentroid(int centroidID) {
    Point newCentroid(dimension);
    int numPoints = 0;
    for (int i = 0; i < n; i++) {
        if (points.at(i).getCentroidId() == centroidID) {
            newCentroid += points.at(i);
            numPoints++;
        }
    }
    if (numPoints != 0) {
        newCentroid /= numPoints;
        centroids.at(centroidID) = newCentroid;
    }
}

void KMeans::execute() {
    int iter = 0;
    do {
        oldCentroids = centroids;
        assignCentroids();
        //printAllPoints();
        //printCentroids();
        moveCentroids();
        iter++;
    } while (hasChanged && ((iter < maxIter) || (maxIter == -1))); //Set maxIter to -1 to remove Max Iteration criteria
}
