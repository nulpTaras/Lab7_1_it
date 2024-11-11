
#include <iostream>
#include <iomanip>
#include "functions.cpp"

int main() {
    srand((unsigned)time(NULL));
    int Low = 8;
    int High = 73;
    int rowCount = 7;
    int colCount = 6;

    int** a = new int*[rowCount];
    for (int i = 0; i < rowCount; i++)
        a[i] = new int[colCount];

    Create(a, rowCount, colCount, Low, High);
    cout << "Original matrix:" << endl;
    Print(a, rowCount, colCount);

    Sort(a, rowCount, colCount);
    cout << "Sorted matrix:" << endl;
    Print(a, rowCount, colCount);

    for (int i = 0; i < rowCount; i++)
        delete[] a[i];
    delete[] a;

    return 0;
}