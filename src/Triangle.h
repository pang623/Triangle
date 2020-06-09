#ifndef TRIANGLE_H
#define TRIANGLE_H

#define	ERROR_INVALID_LENGTH		0x1F

typedef enum {
//     0          1           2         3
	UNKNOWN, EQUILATERAL, ISOSCELES, SCALENE
} TriangleType;

TriangleType getTriangleType(int side1, int side2, int side3);

#endif // TRIANGLE_H
