/**
 * Source: Geeks for Geeks
 * The idea behind templates is to pass data type as a prameter so that we dont need to write the same code for 
 * different data types. For example, the function sort() may be needed for different data types. Rather than writing
 * different codes, we can write one sort function and pass the data type as a parameter. 
 * 
 * Templates are expanded at compiler time, like macros. The compiler does type checking before template expansion. 
 * 
 * Templates vs Overloading: Templates are used when same functions are used for different parameter types.
 * Overloading is used when multiple functions have the same name but have different input parameters and may have 
 * different implementation. 
 * 
 * Each instance of a template contains its own static variable. 
 * 
 * Template Specialization: Template specialization allows for different code for a particular data type. 
 * 
 * Const non parameter values can be pased as arguments to templates.
 */

#include <iostream>

using namespace std;

// One functions can be used for different data types.
template <typename T>
T findMax(T x, T y)
{
    return (x > y) ? x : y;
}

// A template function to implement bubble sort.
template <class F>
void bubbleSort(F a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = n - 1; i < j; j--)
        {
            if (a[j] < a[j - 1])
            {
                swap(a[j], a[j - 1]);
            }
        }
    }
}

int main()
{
    cout << findMax<int>(4, 8) << endl;
    cout << findMax<double>(3.0, 7.0) << endl;
    cout << findMax<char>('g', 'e') << endl;
    int a[5] = {10, 50, 30, 40, 20};
    int n = sizeof(a) / sizeof(a[0]);
    // call the template function for bubble sort
    bubbleSort<int>(a, n);
    cout << "Sorted array : ";
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}