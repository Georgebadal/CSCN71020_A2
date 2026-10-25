
#include <gtest/gtest.h>
#include <iostream>
#include <string>

using namespace std;

extern "C" {
    #include "../BCSRec/functions.h"
}

// Display individual test results
void printTestResult(const char* name, int actual, int expected) {
    EXPECT_EQ(expected, actual);

    cout << "Testing " << name << "  ";

    if (actual == expected) {
        cout << "PASSED" << endl;
    } else {
        cout << "FAILED (Expected: " << expected
             << ", Actual: " << actual << ")" << endl;
    }
}

// Custom Google Test output
class TestPrinter : public testing::EmptyTestEventListener {
public:
    void OnTestProgramStart(const testing::UnitTest&) override {
        cout << "\n=========================================\n";
        cout << "    STARTING UNIT TESTS FOR FUNCTIONS\n";
        cout << "=========================================\n\n";
    }

    void OnTestSuiteStart(const testing::TestSuite& suite) override {
        string name = suite.name();
        string function =
            name == "PerimeterTests" ? "getPerimeter" :
            name == "AreaTests" ? "getArea" :
            name == "LengthTests" ? "setLength" :
            name == "WidthTests" ? "setWidth" : name;

        cout << "Running test_" << function << "..." << endl;
    }

    void OnTestSuiteEnd(const testing::TestSuite& suite) override {
        string name = suite.name();
        string function =
            name == "PerimeterTests" ? "getPerimeter" :
            name == "AreaTests" ? "getArea" :
            name == "LengthTests" ? "setLength" :
            name == "WidthTests" ? "setWidth" : name;

        cout << " -> test_" << function
             << (suite.Passed() ? " passed." : " FAILED.")
             << "\n\n";
    }

    void OnTestProgramEnd(const testing::UnitTest& tests) override {
        cout << "=========================================\n";

        if (tests.Passed()) {
            cout << "   ALL UNIT TESTS PASSED SUCCESSFULLY!\n";
        } else {
            cout << "   SOME UNIT TESTS FAILED!\n";
        }

        cout << "=========================================\n";
        cout << "Total: " << tests.total_test_count()
             << " | Passed: " << tests.successful_test_count()
             << " | Failed: " << tests.failed_test_count()
             << endl;
    }
};

// ==========================================
// TASK 1 - PERIMETER TESTS
// ==========================================

TEST(PerimeterTests, NormalDimensions) {
    // Arrange
    int length = 10;
    int width = 5;

    // Act
    int result = getPerimeter(length, width);

    // Assert
    printTestResult("getPerimeter(10, 5)", result, 30);
}

TEST(PerimeterTests, MinimumDimensions) {
    // Arrange
    int length = 1;
    int width = 1;

    // Act
    int result = getPerimeter(length, width);

    // Assert
    printTestResult("getPerimeter(1, 1)", result, 4);
}

TEST(PerimeterTests, MaximumDimensions) {
    // Arrange
    int length = 99;
    int width = 99;

    // Act
    int result = getPerimeter(length, width);

    // Assert
    printTestResult("getPerimeter(99, 99)", result, 396);
}

TEST(PerimeterTests, MixedBoundaryDimensions) {
    // Arrange
    int length = 1;
    int width = 99;

    // Act
    int result = getPerimeter(length, width);

    // Assert
    printTestResult("getPerimeter(1, 99)", result, 200);
}

// ==========================================
// TASK 1 - AREA TESTS
// ==========================================

TEST(AreaTests, NormalDimensions) {
    // Arrange
    int length = 10;
    int width = 5;

    // Act
    int result = getArea(length, width);

    // Assert
    printTestResult("getArea(10, 5)", result, 50);
}

TEST(AreaTests, MinimumDimensions) {
    // Arrange
    int length = 1;
    int width = 1;

    // Act
    int result = getArea(length, width);

    // Assert
    printTestResult("getArea(1, 1)", result, 1);
}

TEST(AreaTests, MaximumDimensions) {
    // Arrange
    int length = 99;
    int width = 99;

    // Act
    int result = getArea(length, width);

    // Assert
    printTestResult("getArea(99, 99)", result, 9801);
}

TEST(AreaTests, MixedBoundaryDimensions) {
    // Arrange
    int length = 1;
    int width = 99;

    // Act
    int result = getArea(length, width);

    // Assert
    printTestResult("getArea(1, 99)", result, 99);
}

#include <iostream>

// Print test results
void printTask2Result(const char* name, int actual, int expected) {
    std::cout << "Testing " << name << "  ";

    if (actual == expected) {
        std::cout << "PASSED\n";
    } else {
        std::cout << "FAILED (Expected: " << expected
                  << ", Actual: " << actual << ")\n";
    }
}

// ==========================================
// TASK 2 - SET LENGTH TESTS
// ==========================================

TEST(LengthTests, NormalValue) {
    // Arrange
    int input = 63;

    // Act
    int result = setLength(input);

    // Assert
    EXPECT_EQ(63, result);
    printTask2Result("setLength(63)", result, 63);
}

TEST(LengthTests, MinimumValue) {
    // Arrange
    int input = 1;

    // Act
    int result = setLength(input);

    // Assert
    EXPECT_EQ(1, result);
    printTask2Result("setLength(1)", result, 1);
}

TEST(LengthTests, MaximumValue) {
    // Arrange
    int input = 99;

    // Act
    int result = setLength(input);

    // Assert
    EXPECT_EQ(99, result);
    printTask2Result("setLength(99)", result, 99);
}

TEST(LengthTests, BelowMinimum) {
    // Arrange
    int input = 0;

    // Act
    int result = setLength(input);

    // Assert
    EXPECT_EQ(1, result);
    printTask2Result("setLength(0)", result, 1);
}

TEST(LengthTests, AboveMaximum) {
    // Arrange
    int input = 100;

    // Act
    int result = setLength(input);

    // Assert
    EXPECT_EQ(1, result);
    printTask2Result("setLength(100)", result, 1);
}

// ==========================================
// TASK 2 - SET WIDTH TESTS
// ==========================================

TEST(WidthTests, NormalValue) {
    // Arrange
    int input = 50;

    // Act
    int result = setWidth(input);

    // Assert
    EXPECT_EQ(50, result);
    printTask2Result("setWidth(50)", result, 50);
}

TEST(WidthTests, MinimumValue) {
    // Arrange
    int input = 1;

    // Act
    int result = setWidth(input);

    // Assert
    EXPECT_EQ(1, result);
    printTask2Result("setWidth(1)", result, 1);
}

TEST(WidthTests, MaximumValue) {
    // Arrange
    int input = 99;

    // Act
    int result = setWidth(input);

    // Assert
    EXPECT_EQ(99, result);
    printTask2Result("setWidth(99)", result, 99);
}

TEST(WidthTests, BelowMinimum) {
    // Arrange
    int input = -1;

    // Act
    int result = setWidth(input);

    // Assert
    EXPECT_EQ(1, result);
    printTask2Result("setWidth(-1)", result, 1);
}

TEST(WidthTests, AboveMaximum) {
    // Arrange
    int input = 100;

    // Act
    int result = setWidth(input);

    // Assert
    EXPECT_EQ(1, result);
    printTask2Result("setWidth(100)", result, 1);
}

// ==========================================
// RUN GOOGLE TESTS
// ==========================================

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);

    testing::TestEventListeners& listeners =
        testing::UnitTest::GetInstance()->listeners();

    delete listeners.Release(listeners.default_result_printer());

    listeners.Append(new TestPrinter);

    return RUN_ALL_TESTS();
}
