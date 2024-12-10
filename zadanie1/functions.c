#include <functions.h>
#include <stdio.h>

struct Triangle createTriangle(struct Point cornerA, struct Point cornerB, struct Point cornerC)
{
    struct Triangle triangle;
    triangle.cornerA = cornerA;
    triangle.cornerB = cornerB;
    triangle.cornerC = cornerC;
    return triangle;
}
