//
// Created by Benelli, Bindini on 25/01/2021.
//

#include "KMeans.h"

KMeans::KMeans(float *points, int n, int k, int dimension, int maxIter) {
    this->points = points;
    this->n = n;
    this->k = k;
    this->dimension = dimension;
    this->maxIter = maxIter;
    centroids = (float *) malloc(k * dimension * sizeof(float));
    newCentroids = (float *) malloc(k * dimension * sizeof(float));
    pointsPerCluster = (unsigned int *) malloc(n * sizeof(unsigned int));
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < dimension; j++) {
            centroids[j * k + i] = points[j * n + i];
        }
    }

}

float KMeans::pointDistance(int p, int c) {
    float sum = 0;
    for (int j = 0; j < dimension; j++)
        sum += pow((points[j * n + p] - centroids[j * k + c]), 2);
    return sqrt(sum);
}

void KMeans::kMeansIteration() {
    for (int p = 0; p < n; p++) {
        if (p < k) {
            for (int d = 0; d < dimension; d++)
                newCentroids[d * k + p] = 0;
            pointsPerCluster[p] = 0;
        }

        int nearestId = 0;
        float minDistance = pointDistance(p, 0);
        float distance;
        for (int c = 1; c < k; c++) {
            distance = pointDistance(p, c);
            if (distance < minDistance) {
                minDistance = distance;
                nearestId = c;
            }
        }
        pointsPerCluster[nearestId]++;
        for (int d = 0; d < dimension; d++) {
            //printf("\t\t\td = %d\n", d);
            newCentroids[d * k + nearestId] += points[d * n + p];
        }
        if (p < k) {
            for (int d = 0; d < dimension; d++)
                centroids[d * k + p] = newCentroids[d * k + p] / pointsPerCluster[p];
            //printf("\t\t%u points in cluster %d\n", pointsPerCluster[p], p);
        }
    }
}


void KMeans::execute() {
    for (int i = 0; i < maxIter; i++) {
        //printf("\titeration n. %d\n", i);
        kMeansIteration();
    }
}

KMeans::~KMeans() {
    free(centroids);
    free(newCentroids);
    free(pointsPerCluster);
}
