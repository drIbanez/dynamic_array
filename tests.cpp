#include "tests.h"
#include "Array.h"
#include <iostream>

using namespace std;

void ConstructTest()
{
    int size = -4;
    try
    {
        myVector<double> array(size);
    }
    catch(invalid_argument &e)
    {
        cout << "Error occured: " << e.what() << endl;
        cout << "Expected exception, valid case" << endl;
    }
    catch(...)
    {
        if (size < 0)   {
            cout << "Expected exception, valid case" << endl;
        }
        else    {
            cout << "Unspecified exception occured." << endl;
            return;
        }
    }
    cout << "Test complete" << endl;
}

void BackDigTest()
{
    try
    {
        myVector<int> array(3);
        for (int i = 0; i < 3; ++i)
            array[i] = i+1;
        try
        {
            array.push_back('f');
        }
        catch(invalid_argument &e)
        {
            cout << "Error occured: " << e.what() << endl;
            cout << "Expected exception, valid case" << endl;
        }
        catch(...)
        {
            cout << "Unspecified exception occured." << endl;
            return;
        }
    }
    catch(...)
    {
        cout << "Unspecified exception occured." << endl;
        return;
    }
    cout << "Test complete" << endl;
}

void ResizeTest()
{
    int new_size = -3;
    try
    {
        myVector<int> array(3);
        for (int i = 0; i < 3; ++i)
            array[i] = i + 1;
        try
        {
            array.resize(new_size);
            return;
        }
        catch(invalid_argument &e)
        {
           cout << "Error occured: " << e.what() << endl;
           cout << "Expected exception, valid case." << endl;
        }
        catch(...)
        {
            if (new_size < 0)   {
                cout << "Expected exception, valid case" << endl;
            }
            else    {
                cout << "Unspecified exception occured." << endl;
                return;
            }
        }
    }
    catch(...)
    {
        cout << "Unspecified exception occured." << endl;
        return;
    }
    cout << "Test Complete" << endl;
}
