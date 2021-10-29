#include <iostream>
#include <stdlib.h>

using namespace std;

void show(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << ' ';
    }
    cout << endl;
}




int main()
{
    int myArray[100];
    int size = 10;

    // init array
    for (int i = 0; i < size; i++)
    {
        myArray[i] = rand() % 10;
    }

    cout << "Initial array" << endl;
    show(myArray, size);

    return 0;
}