#include <iostream>
#include <stdlib.h>

using namespace std;

int a[100];
int n; // size of array

void show(string msg) // message
{
    cout << msg << endl;
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << ' ';
    }
    cout << endl;
}

//--------------------------
void insert(int value, int pos)
{
    n++; // increase size

    if (pos < n)
    {
        // shift elements 1-step backward
        for (int i = n - 1; i >= pos; i--)
        {
            a[i + 1] = a[i];
        }

        // insert the new element
        a[pos] = value;
    }
    else
    {
        cout << "Invalid position" << endl;
    }
}

//--------------------------
void append(int value)
{   
    a[n] = value;
    n++; // increase size
}

//--------------------------


int main()
{ 
    // init array
    n = 10;
    for (int i = 0; i < n; i++)
    {
        a[i] = rand() % 10;
    }

    // show
    show("Initial array");

    //--------------------------
    // insert to position 6
    int newElement = 77;
    int position = 6;
    insert(newElement, position);
    show("Insert to some position");

    //--------------------------
    // insert to position 6
    newElement = 77;
    position = 0;
    insert(newElement, position);
    show("Insert to the head");

    //--------------------------
    // append
    newElement = 88;
    append(newElement);
    show("Add a new element to the tail");
    
    return 0;
}