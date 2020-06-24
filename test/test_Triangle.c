#include "unity.h"
#include "Triangle.h"
#include "Exception.h"
#include "CException.h"

CEXCEPTION_T ex;

//to ignore certain test, include this code
//TEST_IGNORE_MESSAGE("..");

//Exceptions
//if try catch is included, need to manually rethrow exception to the caller
//if not rethrown manually, the exception catched ends at the called function, the caller will not receive any exception
//if no try catch, exception is automaticallly rethrown back to the caller


void setUp(void)
{
}

void tearDown(void)
{
}

int multiply(int valA, int valB) {
	if(valA < 0 && valB < 0) {
		throwException(ERROR_INVALID_VALUE, NULL, 0, "The valA and valB operand cannot be negative: %d, %d", valA, valB);
	}
	if(valA < 0) {
//		Throw(ERROR_INVALID_VALUE);
		throwException(ERROR_INVALID_VALUE, NULL, 0, "The valA operand cannot be negative: %d", valA);
	}
	if(valB < 0) {
//		Throw(ERROR_INVALID_VALUE);
		throwException(ERROR_INVALID_VALUE, NULL, 0, "The valB operand cannot be negative: %d", valB);
	}
	return valA * valB;
}

int addAndMultiplyPositives(int val1, int val2, int val3) {
	return multiply(val1 + val2, val3);
}

void test_addAndMultiplyPositives_expect_an_exception_to_be_thrown() {
	Try{
	int result = addAndMultiplyPositives(1, -5, -9);
	TEST_FAIL_MESSAGE("Expect ERROR_INVALID_VALUE to be thrown, but none received");
	} Catch(ex) {
		/*
		printf("Found an exception in test_addAndMultiplyPositives_expect_an_exception_to_be_thrown : 0x%x\n", ex);
		if(ex == ERROR_INVALID_VALUE) {
			printf("The operand cannot be negative value\n", ex);
		}else if(ex == ERROR_INVALID_LENGTH) {
			printf("The operand has invalid length\n", ex);
		}
		*/
		dumpException(ex);
		TEST_ASSERT_EQUAL(ERROR_INVALID_VALUE, ex->errorCode);
		freeException(ex);							//only free exception after the exception is no longer be used
													//for example, free exception cannot be used before TEST_ASSERT_EQUAL as 'ex' is used to compare with ERROR_INVALID_VALUE
													//if it is used before TEST_ASSERT_EQUAL, the 'ex' data will be gone before it have any chance to compare with ERROR_INVALID_VALUE
	}
}


void test_getTriangleType_given_3_3_3_expect_EQUILATERAL() {
	Try{
	TriangleType type = getTriangleType(3, 3, 3);
	TEST_ASSERT_EQUAL(EQUILATERAL, type);
	}Catch(ex){
	//supposedly no exception should be thrown, but if thrown, print fail message
	TEST_FAIL_MESSAGE("No exception expected, but an exception is caught");
	}
}

void test_getTriangleType_given_2_2_1_expect_ISOSCELES() {
	TriangleType type = getTriangleType(2, 2, 1);
	TEST_ASSERT_EQUAL(ISOSCELES, type);
}

void test_getTriangleType_given_4_3_4_expect_ISOSCELES() {
	TriangleType type = getTriangleType(4, 3, 4);
	TEST_ASSERT_EQUAL(ISOSCELES, type);
}

void test_getTriangleType_given_10_20_20_expect_ISOSCELES() {
	TriangleType type = getTriangleType(10, 20, 20);
	TEST_ASSERT_EQUAL(ISOSCELES, type);
}

void test_getTriangleType_given_1_2_3_expect_SCALENE() {
	TriangleType type = getTriangleType(1, 2, 3);
	TEST_ASSERT_EQUAL(SCALENE, type);
}

//test for negative and zero inputs
void test_getTriangleType_given_minus2_2_1_expect_ERROR_INVALID_LENGTH_to_be_thrown() {
	Try{
		TriangleType type = getTriangleType(-2, 2, 1);
		TEST_FAIL_MESSAGE("Expect ERROR_INVALID_LENGTH to be thrown, but none received");
		}Catch(ex) {
	dumpException(ex);
//	printf("Found an exception: 0x%x", ex);
//	                 (expected value,exception caught)
	TEST_ASSERT_EQUAL(ERROR_INVALID_LENGTH, ex->errorCode);
	freeException(ex);
	}
}

void test_getTriangleType_given_4_minus2_1_expect_ERROR_INVALID_LENGTH_to_be_thrown() {
	Try{
		TriangleType type = getTriangleType(4, -2, 1);
		TEST_FAIL_MESSAGE("Expect ERROR_INVALID_LENGTH to be thrown, but none received");
		}Catch(ex) {
	dumpException(ex);
	TEST_ASSERT_EQUAL(ERROR_INVALID_LENGTH, ex->errorCode);
	freeException(ex);
	}
}

void test_getTriangleType_given_1_9_minus4_expect_ERROR_INVALID_LENGTH_to_be_thrown() {
	Try{
		TriangleType type = getTriangleType(1, 9, -4);
		TEST_FAIL_MESSAGE("Expect ERROR_INVALID_LENGTH to be thrown, but none received");
		}Catch(ex) {
	dumpException(ex);
	TEST_ASSERT_EQUAL(ERROR_INVALID_LENGTH, ex->errorCode);
	freeException(ex);
	}
}

void test_getTriangleType_given_0_minus8_1_expect_ERROR_INVALID_LENGTH_to_be_thrown() {
	Try{
		TriangleType type = getTriangleType(0, -8, 1);
		TEST_FAIL_MESSAGE("Expect ERROR_INVALID_LENGTH to be thrown, but none received");
		}Catch(ex) {
	dumpException(ex);
	TEST_ASSERT_EQUAL(ERROR_INVALID_LENGTH, ex->errorCode);
	freeException(ex);
	}
}

void test_getTriangleType_given_minus4_0_0_expect_ERROR_INVALID_LENGTH_to_be_thrown() {
	Try{
		TriangleType type = getTriangleType(-4, 0, 0);
		TEST_FAIL_MESSAGE("Expect ERROR_INVALID_LENGTH to be thrown, but none received");
		}Catch(ex) {
	dumpException(ex);
	TEST_ASSERT_EQUAL(ERROR_INVALID_LENGTH, ex->errorCode);
	freeException(ex);
	}
}

void test_getTriangleType_given_9_0_5_expect_ERROR_INVALID_LENGTH_to_be_thrown() {
	Try{
		TriangleType type = getTriangleType(9, 0, 5);
		TEST_FAIL_MESSAGE("Expect ERROR_INVALID_LENGTH to be thrown, but none received");
		}Catch(ex) {
	dumpException(ex);
	TEST_ASSERT_EQUAL(ERROR_INVALID_LENGTH, ex->errorCode);
	freeException(ex);
	}
}

void test_getTriangleType_given_7_minus3_0_expect_ERROR_INVALID_LENGTH_to_be_thrown() {
	Try{
		TriangleType type = getTriangleType(7, -3, 0);
		TEST_FAIL_MESSAGE("Expect ERROR_INVALID_LENGTH to be thrown, but none received");
		}Catch(ex) {
	dumpException(ex);
	TEST_ASSERT_EQUAL(ERROR_INVALID_LENGTH, ex->errorCode);
	freeException(ex);
	}
}

void test_getTriangleType_given_minus1_minus3_minus2_expect_ERROR_INVALID_LENGTH_to_be_thrown() {
	Try{
		TriangleType type = getTriangleType(-1, -3, -2);
		TEST_FAIL_MESSAGE("Expect ERROR_INVALID_LENGTH to be thrown, but none received");
		}Catch(ex) {
	dumpException(ex);
	TEST_ASSERT_EQUAL(ERROR_INVALID_LENGTH, ex->errorCode);
	freeException(ex);
	}
}

void test_getTriangleType_given_0_0_0_expect_ERROR_INVALID_LENGTH_to_be_thrown() {
	Try{
		TriangleType type = getTriangleType(0, 0, 0);
		TEST_FAIL_MESSAGE("Expect ERROR_INVALID_LENGTH to be thrown, but none received");
		}Catch(ex) {
	dumpException(ex);
	TEST_ASSERT_EQUAL(ERROR_INVALID_LENGTH, ex->errorCode);
	freeException(ex);
	}
}

