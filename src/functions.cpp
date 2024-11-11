//
// Created by Taras Neridnyi on 09.11.2024.
//

#include <iostream>
#include <iomanip>
#include <cstdlib>

using namespace std;

void Create(int** a, const int rowCount, const int colCount, const int Low, const int High);
void Print (int** a, const int rowCount, const int colCount);
void Sort  (int** a, const int rowCount, const int colCount);
void Change(int** a, const int row1, const int row2, const int colCount);

void Create(int** a, const int rowCount, const int colCount, const int Low, const int High) {
    for (int i = 0; i < rowCount; i++)
        for (int j = 0; j < colCount; j++)
            a[i][j] = Low + rand() % (High - Low + 1);
}

void Print(int** a, const int rowCount, const int colCount) {
    for (int i = 0; i < rowCount; i++) {
        for (int j = 0; j < colCount; j++)
            cout << setw(4) << a[i][j];
        cout << endl;
    }
    cout << endl;
}

void Sort(int** a, const int rowCount, const int colCount) {
    for (int i0 = 0; i0 < rowCount - 1; i0++) {
        for (int i1 = 0; i1 < rowCount - i0 - 1; i1++) {
            // 1-9
            if (a[i1][0] > a[i1 + 1][0]) {
                Change(a, i1, i1 + 1, colCount);
            }
            // 1 = 1  2 -> 9-1
            else if (a[i1][0] == a[i1 + 1][0] && a[i1][1] < a[i1 + 1][1]) {
                Change(a, i1, i1 + 1, colCount);
            }
            // 1 = 2 4 -> 9-1
            else if (a[i1][0] == a[i1 + 1][0] && a[i1][1] == a[i1 + 1][1] && a[i1][3] < a[i1 + 1][3]) {
                Change(a, i1, i1 + 1, colCount);
            }
        }
    }
}

void Change(int** a, const int row1, const int row2, const int colCount) {
    for (int j = 0; j < colCount; j++) {
        int tmp = a[row1][j];
        a[row1][j] = a[row2][j];
        a[row2][j] = tmp;
    }
}
