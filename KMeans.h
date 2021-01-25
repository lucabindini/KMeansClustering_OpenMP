//
// Created by Benelli, Bindini on 25/01/2021.
//

#ifndef KMEANSCLUSTERING_OPENMP_KMEANS_H
#define KMEANSCLUSTERING_OPENMP_KMEANS_H

#include "Point.h"
#include <cstdlib>
#include <ctime>

class KMeans {
public:
    KMeans(int k, int n, int dimension, int maxIter);

    void execute();

    void printAllPoints();

    void printCentroids();


private:
    int k;
    int n;
    int dimension;
    int maxIter;
    bool hasChanged;
    std::vector<Point> points;
    std::vector<Point> centroids;
    std::vector<Point> oldCentroids;

    void init();

    void assignCentroids();

    void moveCentroids();

    void moveCentroid(int centroidID);

};


#endif //KMEANSCLUSTERING_OPENMP_KMEANS_H
