
#include <stack>
#include <random>
#include <iostream>
#include <chrono>

using namespace std;


void FillArray(int* array, int size, int min, int max)
{
    srand(static_cast<unsigned int>(time(NULL)));
    for (int i = 0; i < size; ++i)
        array[i] = rand() % (max - min + 1) + min;
}

int Search(int* array, int size, int value) 
{
    for (int i = 0; i < size; ++i)
        if (array[i] == value)
            return i;
    return -1;
}

void PrintArray(int* array, string message)
{
    cout << message;
    for (int i = 0; i < 50; ++i)
        cout << array[i] << " ";
    cout << endl;
}

void QuickSortWithRecursion(int* array, int start, int end)
{
    if (start == end) return;
    int pivot = array[end];
    int storeIndex = start;

    for (int i = start; i <= end - 1; i++)
        if (array[i] <= pivot)
        {
            int t = array[i];
            array[i] = array[storeIndex];
            array[storeIndex] = t;
            storeIndex++;
        }

    int n = array[storeIndex];
    array[storeIndex] = array[end];
    array[end] = n;
    if (storeIndex > start) QuickSortWithRecursion(array, start, storeIndex - 1);
    if (storeIndex < end) QuickSortWithRecursion(array, storeIndex + 1, end);
}

void QuickSort(int* array, int left, int right)
{
    int mid, start, end, i, j;
    stack<int> stack;

    stack.push(right - 1);
    stack.push(left);
    while (!stack.empty())
    {                 
        start = stack.top();
        stack.pop();
        end = stack.top();
        stack.pop();
        if (((end - start) == 1) && (array[start] > array[end]))
            swap(array[start], array[end]);
        else 
        {
            mid = array[(start + end) / 2];
            i = start;
            j = end;
            while (i <= j)
            {       
                while ((mid > array[i]))
                    ++i;
                while (array[j] > mid)
                    --j;
                swap(array[i++], array[j--]);
            }
        }
        if (start < j) 
        {
            stack.push(j);
            stack.push(start);
        }
        if (i < end) 
        {
            stack.push(end);
            stack.push(i);
        }
    } 
}

int BSearch(int value, int* array, int left, int right)
{
    while (right >= left)
    {
        int mid = (right + left) / 2;
        if (array[mid] == value)
            return mid;
        if (value < array[mid])
            right = mid - 1;
        if (value > array[mid])
            left = mid + 1;
    }
    return -1;
}

int BSearchWithRecursion(int value, int* array, int left, int right)
{
    int mid = (right + left) / 2;
    if (array[mid] == value)
        return mid;
    if (value < array[mid])
        return BSearchWithRecursion(value, array, left, mid - 1 );
    if (value > array[mid])
        return BSearchWithRecursion(value, array, mid + 1, right);
    return -1;
}


int main()
{
    setlocale(LC_ALL, "Russian"); // Жиляев Вячеслав РИ-280001
    int* firstArray = new int[10000];
    FillArray(firstArray, 10000, -1000, 1000);
    PrintArray(firstArray, "Массив от -1000 до 1000:  ");
    int search = Search(firstArray, 10000, 666);
    if ( search != -1)
        cout << "Простой поиск:  " << search << endl;
    else cout << "Число не найдено" << endl;

    int* secondArray = new int[100];
    FillArray(secondArray, 100, -10, 10);
    PrintArray(secondArray, "Второй массив до сортировки:  ");
    QuickSortWithRecursion(secondArray, 0, 99);
    PrintArray(secondArray, "Второй массив после сортировки:  ");

    int* thirdArray = new int[100];
    FillArray(thirdArray, 100, -10, 10);
    PrintArray(thirdArray, "Третий массив до сортировки:  ");
    QuickSort(thirdArray, 0, 99);
    PrintArray(thirdArray, "Третий массив после сортировки без рекурсии:  ");

    int arrayForBinarySearch[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    cout << "Бинарный поиск:  " << BSearch(6, arrayForBinarySearch, 0, 8) << endl;
    cout << "Бинарный поиск с рекурсией:  " << BSearchWithRecursion(7, arrayForBinarySearch, 0, 8) << endl;

    int* arrayForTimings = new int[1000];
    FillArray(arrayForTimings, 1000, -500, 500);
    PrintArray(arrayForTimings, "Массив для сравнения скорости:  ");

    auto begin1 = std::chrono::high_resolution_clock::now();
    Search(arrayForTimings, 1000, 20);
    auto end1 = std::chrono::high_resolution_clock::now();
    auto elapsed_ms1 = std::chrono::duration_cast<std::chrono::nanoseconds>(end1 - begin1).count();
    cout << "Скорость в неотсортированном:  " << elapsed_ms1 << "ns\n";

    QuickSortWithRecursion(arrayForTimings, 0, 999);

    auto begin2 = std::chrono::high_resolution_clock::now();
    BSearch(20, arrayForTimings, 0, 999);
    auto end2 = std::chrono::high_resolution_clock::now();
    auto elapsed_ms2 = std::chrono::duration_cast<std::chrono::nanoseconds>(end2 - begin2).count();
    cout << "Скорость в отсортированном:  " << elapsed_ms2  << "ns\n";
    return 0;
}
    


