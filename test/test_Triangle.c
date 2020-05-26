#include "unity.h"

#include "Triangle.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_getTriangleType_given_3_3_3_expect_EQUILATERAL() {
	TriangleType type = getTriangleType(3, 3, 3);
	TEST_ASSERT_EQUAL(EQUILATERAL, type);
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

// random tests for zero and negative inputs of side1, side2, side3, any of these inputs will results in an unknown type
void test_checkTriangleSideNegativeORzero_given_0_0_0_expect_UNKNOWN() {
	TriangleType type = checkTriangleSideNegativeORzero(0, 0, 0);
	TEST_ASSERT_EQUAL(UNKNOWN, type);
}

void test_checkTriangleSideNegativeORzero_given_MINUS1_0_1_expect_UNKNOWN() {
	TriangleType type = checkTriangleSideNegativeORzero(-1, 0, 1);
	TEST_ASSERT_EQUAL(UNKNOWN, type);
}

void test_checkTriangleSideNegativeORzero_given_1_MINUS1_0_expect_UNKNOWN() {
	TriangleType type = checkTriangleSideNegativeORzero(1, -1, 0);
	TEST_ASSERT_EQUAL(UNKNOWN, type);
}

void test_checkTriangleSideNegativeORzero_given_0_1_MINUS1_expect_UNKNOWN() {
	TriangleType type = checkTriangleSideNegativeORzero(0, 1, -1);
	TEST_ASSERT_EQUAL(UNKNOWN, type);
}

void test_checkTriangleSideNegativeORzero_given_0_0_MINUS1_expect_UNKNOWN() {
	TriangleType type = checkTriangleSideNegativeORzero(0, 0, -1);
	TEST_ASSERT_EQUAL(UNKNOWN, type);
}

void test_checkTriangleSideNegativeORzero_given_MINUS1_MINUS1_0_expect_UNKNOWN() {
	TriangleType type = checkTriangleSideNegativeORzero(-1, -1, 0);
	TEST_ASSERT_EQUAL(UNKNOWN, type);
}

void test_checkTriangleSideNegativeORzero_given_MINUS1_1_0_expect_UNKNOWN() {
	TriangleType type = checkTriangleSideNegativeORzero(-1, 1, 0);
	TEST_ASSERT_EQUAL(UNKNOWN, type);
}

void test_checkTriangleSideNegativeORzero_given_MINUS1_0_MINUS1_expect_UNKNOWN() {
	TriangleType type = checkTriangleSideNegativeORzero(-1, 0, -1);
	TEST_ASSERT_EQUAL(UNKNOWN, type);
}

void test_checkTriangleSideNegativeORzero_given_0_MINUS1_MINUS1_expect_UNKNOWN() {
	TriangleType type = checkTriangleSideNegativeORzero(0, -1, -1);
	TEST_ASSERT_EQUAL(UNKNOWN, type);
}

void test_checkTriangleSideNegativeORzero_given_MINUS1_MINUS1_MINUS1_expect_UNKNOWN() {
	TriangleType type = checkTriangleSideNegativeORzero(-1, -1, -1);
	TEST_ASSERT_EQUAL(UNKNOWN, type);
}