//
// Created by Benelli, Bindini on 25/01/2021.
//

#ifndef KMEANSCLUSTERING_OPENMP_KMEANS_H
#define KMEANSCLUSTERING_OPENMP_KMEANS_H

#include <iostream>
#include <cmath>

class KMeans {
public:
    KMeans(float *points, int n, int k, int dimension, int maxIter);

    void execute();

    ~KMeans();


private:
    int n;
    int k;
    int dimension;
    int maxIter;
    float *points;
    float *centroids;
    float *newCentroids;
    unsigned int *pointsPerCluster;

    float pointDistance(int p, int c);

    void kMeansIteration();

};


#endif //KMEANSCLUSTERING_OPENMP_KMEANS_H
