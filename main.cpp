#include <random>
#include <chrono>

#include "KMeans.h"

#define DIM 2
#define MAX_ITER 64

void generatePoints(float *points, std::mt19937 gen, int n);
void printPoints(float *points, int num);


int main() {
    std::random_device rd;
    std::mt19937 gen(rd());
    float *points; // points[i][j] = points[i*J+j] I=n J=dim
    int numTests = 1;

    for (int n = 4; n <= 65536; n *= 2) { // 4 <= n <= 65536
        printf("n = %d\n", n);
        points = (float *) malloc(n * DIM * sizeof(float));

        for (int k = 2; k < n; k *= 2) { // 2 <= k < n
            printf("\tk = %d\n", k);
            int time = 0;
            for (int i = 0; i < numTests; i++) {
                generatePoints(points, gen, n);
                auto start = std::chrono::system_clock::now();
                KMeans kMeans(points, n, k, DIM, MAX_ITER);
                kMeans.execute();

                auto end = std::chrono::system_clock::now();
                auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
                time += elapsed.count();
            }
            time /= numTests;
            std::cout << "\t\tTime: " << time << std::endl;
        }
        free(points);
    }
}

void generatePoints(float *points, std::mt19937 gen, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < DIM; j++) {
            points[j * n + i] = std::generate_canonical<float, 10>(gen);
        }
    }
}

void printPoints(float *points, int num) {
    for (int i = 0; i < num; i++) {
        for (int j = 0; j < DIM; j++)
            printf("%f ", points[j * num + i]);
        printf("\n");
    }
}
