#include "Triangle.h"
#include "CException.h"

//TDD = Test-Driven Development
//1. Write 1 test.
//2. Run the test, if it fails proceed to 3. Otherwise goto 1.
//3. Write the code to pass the test.
//4. If the test fails, goto 3. Otherwise continue to 1.

/*
 *Find out if a given triangle is one of the following types:
 *	EQUILATERAL		= all has equal sides
 *	ISOSCELES		= 2 has equal sides
 *	SCALENE 		= no equal sides
 */

//Exception is thrown when any of the inputs/sides are of negative or zero.

TriangleType getTriangleType(int side1, int side2, int side3){
	
	if(side1 <= 0)
	{
		throwException(ERROR_INVALID_LENGTH, NULL, 0, "Side 1 cannot be a value of zero or negative: %d", side1);
		//Throw(ERROR_INVALID_LENGTH);
	}
	if(side2 <= 0)
	{
		throwException(ERROR_INVALID_LENGTH, NULL, 0, "Side 2 cannot be a value of zero or negative: %d", side2);
	}
	if(side3 <= 0)
	{
		throwException(ERROR_INVALID_LENGTH, NULL, 0, "Side 3 cannot be a value of zero or negative: %d", side3);
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




	
	