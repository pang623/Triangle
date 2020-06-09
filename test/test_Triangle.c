#include "unity.h"
#include "Triangle.h"
#include "CException.h"


CEXCEPTION_T ex;


void setUp(void)
{
}

void tearDown(void)
{
}

void test_getTriangleType_given_3_3_3_expect_EQUILATERAL() {
	Try{
	TriangleType type = getTriangleType(3, 3, 3);
	TEST_ASSERT_EQUAL(EQUILATERAL, type);
	}Catch(ex){
	//supposedly no exception should be thrown, but if thrown print fail message
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
	printf("Found an exception: 0x%x", ex);
//	                 (expected value,exception caught) 
	TEST_ASSERT_EQUAL(ERROR_INVALID_LENGTH, ex);
	}
}

void test_getTriangleType_given_4_minus2_1_expect_ERROR_INVALID_LENGTH_to_be_thrown() {
	Try{
		TriangleType type = getTriangleType(4, -2, 1);
		TEST_FAIL_MESSAGE("Expect ERROR_INVALID_LENGTH to be thrown, but none received");
		}Catch(ex) {
	printf("Found an exception: 0x%x", ex);
	TEST_ASSERT_EQUAL(ERROR_INVALID_LENGTH, ex);
	}
}

void test_getTriangleType_given_1_9_minus4_expect_ERROR_INVALID_LENGTH_to_be_thrown() {
	Try{
		TriangleType type = getTriangleType(1, 9, -4);
		TEST_FAIL_MESSAGE("Expect ERROR_INVALID_LENGTH to be thrown, but none received");
		}Catch(ex) {
	printf("Found an exception: 0x%x", ex);
	TEST_ASSERT_EQUAL(ERROR_INVALID_LENGTH, ex);
	}
}

void test_getTriangleType_given_0_minus8_1_expect_ERROR_INVALID_LENGTH_to_be_thrown() {
	Try{
		TriangleType type = getTriangleType(0, -8, 1);
		TEST_FAIL_MESSAGE("Expect ERROR_INVALID_LENGTH to be thrown, but none received");
		}Catch(ex) {
	printf("Found an exception: 0x%x", ex);
	TEST_ASSERT_EQUAL(ERROR_INVALID_LENGTH, ex);
	}
}

void test_getTriangleType_given_minus4_0_0_expect_ERROR_INVALID_LENGTH_to_be_thrown() {
	Try{
		TriangleType type = getTriangleType(-4, 0, 0);
		TEST_FAIL_MESSAGE("Expect ERROR_INVALID_LENGTH to be thrown, but none received");
		}Catch(ex) {
	printf("Found an exception: 0x%x", ex);
	TEST_ASSERT_EQUAL(ERROR_INVALID_LENGTH, ex);
	}
}

void test_getTriangleType_given_9_0_5_expect_ERROR_INVALID_LENGTH_to_be_thrown() {
	Try{
		TriangleType type = getTriangleType(9, 0, 5);
		TEST_FAIL_MESSAGE("Expect ERROR_INVALID_LENGTH to be thrown, but none received");
		}Catch(ex) {
	printf("Found an exception: 0x%x", ex);
	TEST_ASSERT_EQUAL(ERROR_INVALID_LENGTH, ex);
	}
}

void test_getTriangleType_given_7_minus3_0_expect_ERROR_INVALID_LENGTH_to_be_thrown() {
	Try{
		TriangleType type = getTriangleType(7, -3, 0);
		TEST_FAIL_MESSAGE("Expect ERROR_INVALID_LENGTH to be thrown, but none received");
		}Catch(ex) {
	printf("Found an exception: 0x%x", ex);
	TEST_ASSERT_EQUAL(ERROR_INVALID_LENGTH, ex);
	}
}

void test_getTriangleType_given_minus1_minus3_minus2_expect_ERROR_INVALID_LENGTH_to_be_thrown() {
	Try{
		TriangleType type = getTriangleType(-1, -3, -2);
		TEST_FAIL_MESSAGE("Expect ERROR_INVALID_LENGTH to be thrown, but none received");
		}Catch(ex) {
	printf("Found an exception: 0x%x", ex);
	TEST_ASSERT_EQUAL(ERROR_INVALID_LENGTH, ex);
	}
}

void test_getTriangleType_given_0_0_0_expect_ERROR_INVALID_LENGTH_to_be_thrown() {
	Try{
		TriangleType type = getTriangleType(0, 0, 0);
		TEST_FAIL_MESSAGE("Expect ERROR_INVALID_LENGTH to be thrown, but none received");
		}Catch(ex) {
	printf("Found an exception: 0x%x", ex);
	TEST_ASSERT_EQUAL(ERROR_INVALID_LENGTH, ex);
	}
}

