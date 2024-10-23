#include <gtest/gtest.h>
#include <math.h>

/**
 * @brief Tests the square root function for positive numbers.
 */
TEST(SquareRootTest, PositiveNos) {
    EXPECT_EQ(28.0, sqrt(784.0));  //!< Expecting square root of 784 to be 28.0
}

/**
 * @class SolverTest
 * @brief Test fixture for solving tests.
 */
class SolverTest : public ::testing::Test {
protected:
    /**
     * @brief Sets up the test environment before each test case.
     *
     * Initializes the member variable n to 1.
     */
    void SetUp() override {
        n = 1;  //!< Initialize n to 1
    }

    // void TearDown() override {}  // Optional: Implement if you need cleanup after tests

    int n = 0;  //!< Variable to hold the test state
};

/**
 * @brief Tests the Solver functionality.
 *
 * Verifies that the value of n is set to 1 during the setup.
 */
TEST_F(SolverTest, Solver) {
    EXPECT_EQ(n, 1);  //!< Expecting n to be 1 after SetUp
}
