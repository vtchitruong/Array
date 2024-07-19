#include <iostream>
// #include <stdlib.h>

using namespace std;

const int MAX = 1000; // hằng số, đồng thời là kích thước tối đa của mảng
int Arr[MAX];
int num; // số phần tử thực dùng


// Khởi tạo giá trị cho n phần tử trong mảng
void initArray(int a[], int n)
{
    // Seed the random number generator
    // srand(time(0));

    for (int i = 0; i < n; i++)
    {
        a[i] = rand() % 10;
    }
}


// In mảng theo hàng ngang
void showArray(int a[], int n, const string& message)
{
    cout << message << endl;
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << ' ';
    }
    cout << endl;
}


// Tính tổng các phần tử trong mảng
int sumArray(int a[], int n)
{
    int s = 0;
    for (int i = 0; i < n; i++)
    {
        s += a[i];
    }
    return s;
}


// Tính trung bình cộng
float average(int a[], int n)
{
    float res = (float) sumArray(a, n) / n;
    return res;
}


// Thêm một phần tử vào cuối mảng
void append(int value)
{
    if (num < MAX)
    {
        Arr[num++] = value;
    }
    else
    {
        cout << "The array is full." << endl;
    }
}


// Chèn phần tử mới vào vị trí giữa mảng
void insert(int value, int pos)
{
    // Kiểm tra pos nằm ngoài phạm vi cho phép
    if (pos < 0 || pos > num)
    {
        cout << "Position out of range." << endl;
        return;
    }

    // Kiểm tra mảng đã đầy
    if (num >= MAX)
    {
        cout << "Array is full." << endl;
        return;
    }

    // Đẩy các phần tử ra sau một vị trí
    for (int i = num; i > pos; i--)
    {
        Arr[i] = Arr[i - 1];
    }

    // Chèn phần tử mới vào vị trí trống
    Arr[pos] = value;
    num++;
}


// Xoá phần tử đầu tiên
void removeFirst()
{
    if (num == 0)
    {
        cout << "Array is empty";
        return;
    }

    // Đẩy các phần tử về trước một vị trí
    for (int i = 1; i < num; i++)
    {
        Arr[i - 1] = Arr[i];
    }

    num--;
}


// Xoá phần tử cuối
void removeLast()
{
    if (num == 0)
    {
        cout << "Array is empty";
        return;
    }
    
    // Giảm số phần tử
    num--;
}


// Xoá phần tử tại vị trí cho trước
void removeAt(int pos)
{
    if (pos < 0 || pos >= num)
    {
        cout << "Position out of range." << endl;
    }

    // Đẩy các phần tử qua trái một vị trí
    for (int i = pos; i < num - 1; i++)
    {
        Arr[i] = Arr[i + 1];
    }

    num--;
}


int main()
{ 
    num = 10; 
    initArray(Arr, num);
    showArray(Arr, num, "Initial array:");

    int sum = sumArray(Arr, num);
    cout << "Sum: " << sum << endl;

    float avg = average(Arr, num);
    cout << "Average: " << avg << endl;

    int valueToAppend = 999;
    append(valueToAppend);
    showArray(Arr, num, "Append:");

    int valueToInsert = 777;
    int positionToInsert = 6;
    insert(valueToInsert, positionToInsert);
    showArray(Arr, num, "Insert:");

    removeFirst();
    showArray(Arr, num, "Remove first:");

    removeLast();
    showArray(Arr, num, "Remove last:");

    int positionToRemove = 5;
    removeAt(positionToRemove);
    showArray(Arr, num, "Remove:");

    return 0;
}