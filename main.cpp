#include <iostream>
#include "KMeans.h"
#include <chrono>

int main() {
    auto start = std::chrono::system_clock::now();
    KMeans kmeans(5, 10000, 20, 10);
    kmeans.execute();
    auto end = std::chrono::system_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    std::cout<<std::endl;
    std::cout << "Tempo: " << elapsed.count();
    return 0;
}
