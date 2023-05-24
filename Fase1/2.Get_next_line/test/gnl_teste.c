#include "unity.h"
#include "unity_fixture.h"
#include "get_next_line.h"

TEST_GROUP(gnl_test);

TEST_SETUP(gnl_test)
{
}

TEST_TEAR_DOWN(gnl_test)
{
}

TEST(gnl_test, should_return_the_right_position)
{
	char	*str1 = "hello World";
	char	c = 'W';

	TEST_ASSERT_EQUAL(str1 + 6, ft_strchr(str1, c));
}

TEST(ft_strchr_test, should_return_NULL_if_str_is_null)
{
	char	*str1 = NULL;
	char	c = 0;

	TEST_ASSERT_EQUAL_STRING(NULL , ft_strchr(str1, c));
}

#include "get_next_line.h"
#include "unity.h"
#include <stdio.h>
#include <string.h>

// Define the path to the file containing the expected result
#define EXPECTED_RESULT_FILE "expected_result.txt"

// Define the path to the file you want to test
#define TEST_FILE "test_file.txt"

// Test function to compare the output of get_next_line with the expected result
void test_get_next_line()
{
    FILE* expected_file = fopen(EXPECTED_RESULT_FILE, "r");
    if (expected_file == NULL)
    {
        TEST_FAIL_MESSAGE("Failed to open expected result file.");
        return;
    }

    FILE* test_file = fopen(TEST_FILE, "r");
    if (test_file == NULL)
    {
        fclose(expected_file);
        TEST_FAIL_MESSAGE("Failed to open test file.");
        return;
    }

    char* expected_result = NULL;
    char* line = NULL;
    size_t len = 0;
    ssize_t read;

    // Read the expected result from the file
    while ((read = getline(&expected_result, &len, expected_file)) != -1)
    {
        // Remove newline character from the end of the line
        if (expected_result[read - 1] == '\n')
            expected_result[read - 1] = '\0';

        // Call get_next_line to retrieve the output
        char* output = get_next_line(fileno(test_file));

        // Compare the output with the expected result
        TEST_ASSERT_EQUAL_STRING(expected_result, output);

        free(output);
    }

    free(expected_result);
    fclose(expected_file);
    fclose(test_file);
}

// Unity test runner
int main()
{
    UNITY_BEGIN();
    RUN_TEST(test_get_next_line);
    UNITY_END();

    return 0;
}
