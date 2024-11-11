// test_functions.cpp
#include <gtest/gtest.h>
#include <iostream>
#include <iomanip>
#include "/Users/tarasneridnyi/Desktop/beta/Lab7_1_it/src/functions.cpp"

TEST(TEST1, TESTSortFunction) {
    const int rowCount = 4, colCount = 4;
    int* a[rowCount];
    for (int i = 0; i < rowCount; i++) {
        a[i] = new int[colCount];
    }

    // Set up test data
    a[0][0] = 5; a[0][1] = 2; a[0][2] = 8; a[0][3] = 1;
    a[1][0] = 3; a[1][1] = 4; a[1][2] = 6; a[1][3] = 7;
    a[2][0] = 5; a[2][1] = 1; a[2][2] = 2; a[2][3] = 9;
    a[3][0] = 5; a[3][1] = 2; a[3][2] = 4; a[3][3] = 6;

    Sort(a, rowCount, colCount);

    for (int i = 0; i < rowCount - 1; i++) {
        EXPECT_LE(a[i][0], a[i + 1][0]);
    }
    for (int i = 0; i < rowCount - 1; i++) {
        if (a[i][0] == a[i + 1][0]) {
            EXPECT_GE(a[i][1], a[i + 1][1]);
        }
    }

    for (int i = 0; i < rowCount - 1; i++) {
        if (a[i][0] == a[i + 1][0] && a[i][1] == a[i + 1][1]) {
            EXPECT_GE(a[i][3], a[i + 1][3]);
        }
    }

    for (int i = 0; i < rowCount; i++) {
        delete[] a[i];
    }
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}