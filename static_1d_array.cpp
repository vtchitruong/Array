#include <iostream>

using namespace std;

const int MAX = 1000; // hằng số, đồng thời là kích thước tối đa của mảng
int Arr[MAX]; // khai báo mảng Arr có MAX phần tử
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
    cout << message << '\n';
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << ' ';
    }
    cout << '\n';
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
void append(int a[], int *n, int value)
{
    if (*n == MAX)
    {
        cout << "The array is full.\n";
    }
    
    a[(*n)++] = value;
}


// Chèn phần tử mới vào vị trí giữa mảng
void insert(int a[], int *n, int position, int value)
{
    // Kiểm tra position nằm ngoài phạm vi cho phép
    if (position < 0 || position > *n)
    {
        cout << "Position out of range.\n";
        return;
    }

    // Kiểm tra mảng đã đầy
    if (*n >= MAX)
    {
        cout << "Array is full.\n";
        return;
    }

    // Đẩy các phần tử ra sau một vị trí
    for (int i = *n; i > position; i--)
    {
        a[i] = a[i - 1];
    }

    // Chèn phần tử mới vào vị trí trống
    a[position] = value;
    (*n)++;
}


// Xoá phần tử cuối
void removeLast(int a[], int *n)
{
    if (*n == 0)
    {
        cout << "Array is already empty.\n";
        return;
    }
    
    // Giảm số phần tử
    (*n)--;
}


// Xoá phần tử tại vị trí cho trước
void removeAt(int a[], int *n, int position)
{
    if (position < 0 || position >= *n)
    {
        cout << "Position out of range.\n";
    }

    // Đẩy các phần tử qua trái một vị trí
    for (int i = position; i < *n - 1; i++)
    {
        a[i] = a[i + 1];
    }

    (*n)--;
}


int main()
{ 
    num = 10; 
    initArray(Arr, num);
    showArray(Arr, num, "Initial array:");

    int sum = sumArray(Arr, num);
    cout << "Sum: " << sum << '\n';

    float avg = average(Arr, num);
    cout << "Average: " << avg << '\n';

    int valueToAppend = 999;
    append(Arr, &num, valueToAppend);
    showArray(Arr, num, "Append:");

    int valueToInsert = 777;
    int positionToInsert = 6;
    insert(Arr, &num, positionToInsert, valueToInsert);
    showArray(Arr, num, "Insert:");

    removeLast(Arr, &num);
    showArray(Arr, num, "Remove last:");

    int positionToRemove = 6;
    removeAt(Arr, &num, positionToRemove);
    showArray(Arr, num, "Remove at some position:");

    return 0;
}