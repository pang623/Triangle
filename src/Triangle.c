#include "Triangle.h"
#include "CException.h"

TriangleType getTriangleType(int side1, int side2, int side3){
	
	if(side1 <= 0 || side2 <= 0 || side3 <= 0)
	{
		Throw(ERROR_INVALID_LENGTH);
	}
	
	if(side1 == side2 && side2 == side3)
	{
		return EQUILATERAL;
	}
	else if(side1 == side2 || side1 == side3 || side2 == side3)
	{
		return ISOSCELES;
	}
	else
	{
		return SCALENE;
	}
}




	
	