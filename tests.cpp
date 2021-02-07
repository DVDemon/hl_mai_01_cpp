#include <gtest/gtest.h>
#include "config.h"

TEST(test_basic, basic_test_set)
{
    testing::internal::CaptureStdout();
    std::cout << "result:" << complex_calculation(2,2);

    std::string output = testing::internal::GetCapturedStdout();
    ASSERT_TRUE(output == "result:4");
}


int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}