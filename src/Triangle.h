#ifndef TRIANGLE_H
#define TRIANGLE_H

typedef enum {
//     0          1           2         3
	UNKNOWN, EQUILATERAL, ISOSCELES, SCALENE
} TriangleType;

TriangleType checkTriangleSideNegativeORzero(int side1, int side2, int side3);
TriangleType getTriangleType(int side1, int side2, int side3);


#endif // TRIANGLE_H
