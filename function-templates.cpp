// Week 41 8 Oct 2021
#include <iostream>

template <typename T>
T myMax(T x, T y)
{
    return (x > y) ? x : y;
}

template <class T>
void bubbleSort(T a[], int n)
{
    for(int i = 0; i < n-1; i++)
    {
        for(int j = n-1; i < j; j--)
        {
            if(a[j] < a[j-1])
                std::swap(a[j], a[j-1]);
        }
    }
}

template <class T>
void printArray(T a[], int n)
{
    for(int i = 0; i < n; i++)
        std::cout << a[i] << " ";
    std::cout << std::endl;
}

int main()
{
    //std::cout << myMax<int>(3, 7) << std::endl;
    //std::cout << myMax<float>(3.1f, 7.2f) << std::endl;
    //std::cout << myMax<char>('g', 'e') << std::endl;

    int a[5] = {10, 50, 30, 40, 20};
    int n = sizeof(a) / sizeof(a[0]);

    bubbleSort<int>(a, n);
    std::cout << "Sorted array : ";
    printArray<int>(a, n);

    double d[6] = {10.5, 60.8, 30.2, 21.34, 15.67, 45.34};
    n = sizeof(d) / sizeof(d[0]);
    bubbleSort<double>(d, n);
    std::cout << "Sorted array : ";
    printArray<double>(d, n);

    return 0;
}