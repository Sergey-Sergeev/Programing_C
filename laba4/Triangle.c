#include "Triangle.h"
#include <math.h>
#include <stdbool.h>

bool IsTriangleExist(double a, double b, double c)
{    
    return (a + b > c) && (a + c > b) && (b + c > a);
}

double CalcTrianglePerimetr(double a, double b, double c)
{
    return a + b + c;
}

double CalcTriangleSquare(double a, double b, double c)
{
    double p = CalcTrianglePerimetr(a, b, c) / 2;
    return sqrtl(p * (p - a) * (p - b) * (p - c));
}
