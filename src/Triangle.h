#ifndef TRIANGLE_H
#define TRIANGLE_H

#define	ERROR_INVALID_LENGTH		0x1F
#define	ERROR_INVALID_VALUE			0x10

typedef enum {
//     0          1           2    
	EQUILATERAL, ISOSCELES, SCALENE
} TriangleType;

TriangleType getTriangleType(int side1, int side2, int side3);
int addAndMultiplyPositives(int val1, int val2, int val3);
int multiply(int valA, int valB);

#endif // TRIANGLE_H
