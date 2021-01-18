#include <iostream>
#include "Point.h"

int main() {
    Point p1({1, 2});
    Point p2({1, 2});
    p1 += p2;

    return 0;
}
