/*
 * testsource.c
 *
 *  Created on: 29 nov. 2023
 *      Author: asier
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "CUnit.h"
#include "source.h"
// This is a test case used to test add() function in source.c
static void test_Add_01(void) {
// Equal Assertion is used in this test case.
// 1 is expected value, and add(1,0) is actual return value.
// If expected value is not same, assertion occurs.
// We can refer the Reference document for the other useful assertion.
CU_ASSERT_EQUAL(2, add(2,0));
}
static void test_Add_02(void) {
CU_ASSERT_EQUAL(10, add(1,9));
}

static void test_Add_03(void) {
 CU_ASSERT_EQUAL(5, add(2,3));
}

static void test_Add_04(void) {
 CU_ASSERT_EQUAL(5, add(2,3));
}

// This is a test case used to test subtract() function in source.c
static void test_Subtract(void) {
// 0 is expected value, and subtract(1,1) is actual return value.
// If expected value is not same, assertion occurs.
CU_ASSERT_EQUAL(0, subtract(1,1));
}
// This is a test suite
static CU_TestInfo tests_Add[] = {
// Register test case to test suite
{"test_Add_01", test_Add_01},
{"test_Add_02", test_Add_02},
{"test_Add_03", test_Add_03},
{"test_Add_04", test_Add_04},
CU_TEST_INFO_NULL,
};
static CU_TestInfo tests_Subtract[] = {
{"test_Subtract", test_Subtract},
CU_TEST_INFO_NULL,
};
// Declare the test suite in SuiteInfo
static CU_SuiteInfo suites[] = {
{"TestSimpleAssert_AddSuite", NULL, NULL, tests_Add},
{"TestSimpleAssert_SubtractSuite", NULL, NULL, tests_Subtract},
CU_SUITE_INFO_NULL,
};
void AddTests(void) {
// Retrieve a pointer to the current test registry
assert(NULL != CU_get_registry());
// Flag for whether a test run is in progress
assert(!CU_is_test_running());
// Register the suites in a single CU_SuiteInfo array
if (CU_register_suites(suites) != CUE_SUCCESS) {
// Get the error message
printf("Suite registration failed - %s\n", CU_get_error_msg());
exit(EXIT_FAILURE);
}
}
