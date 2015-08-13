#include <iostream>
#include "Array.h"
#include <ctime>
#include <stdexcept>
#include "tests.h"

using namespace std;

int main()
{
    cout << "Resisze test: " << endl;
    ResizeTest();
    cout << endl;
    cout << "Constructor test: " << endl;
    ConstructTest();
    cout << endl;
    cout << "Push back test: " << endl;
    BackDigTest();
    cout << endl;
    myVector<int> Array(3);
    Array[0] = 2;
    Array[1] = 5;
    Array[2] = 1;
    Array.Show();
    cout << "Sort" << endl;
    Array.sort();
    Array.Show();
    cout << endl;
    return 0;
}
