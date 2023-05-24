#include "unity_fixture.h"

TEST_GROUP_RUNNER(gnl_test)
{
	RUN_TEST_CASE(gnl_test, should_return_correct_string_lenght);
}

static void	run_all_tests(void)
{
	RUN_TEST_GROUP(gnl_test);
}

int	main(int argc, const char *argv[])
{
	return (UnityMain(argc, argv, run_all_tests));
}
