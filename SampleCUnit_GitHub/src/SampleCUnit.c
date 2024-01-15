#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Basic.h"
int main(void);
extern void AddTests();

int CU_main(void)
{
    // Define the run mode for the basic interface
    // Verbose mode - maximum output of run details
    CU_BasicRunMode mode = CU_BRM_VERBOSE;
    // Define error action
    // Runs should be continued when an error condition occurs (if possible)
    CU_ErrorAction error_action = CUEA_IGNORE;
    // Initialize the framework test registry
    if (CU_initialize_registry()) {
        printf("Initialization of Test Registry failed.\n");
    }
    else {
        // Call add test function
        AddTests();
        // Set the basic run mode, which controls the output during test runs
        CU_basic_set_mode(mode);
        // Set the error action
        CU_set_error_action(error_action);
        // Run all tests in all registered suites
        printf("Tests completed with return value %d.\n",
        CU_basic_run_tests());
        // Clean up and release memory used by the framework
        CU_cleanup_registry();
    }
    return 0;
}
