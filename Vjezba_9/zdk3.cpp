#include <iostream>
#include <cstdlib>

using namespace std;
template <typename T>
void _sort(T arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] > arr[j])
            {
                T temp;
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

template <>
void _sort(char arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (tolower(arr[i]) > tolower(arr[j]))
            {
                char temp;
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}


int main()
{
    int iarr[] = { 3,2,5,7,1,8,4 };
    int in = sizeof(iarr) / sizeof(int);
    char carr[] = { 'a','F','g','w','X' };
    int cn = sizeof(carr) / sizeof(char);
    _sort(iarr, in);
    _sort(carr, cn);
    for (int i = 0; i < in; i++)
    {
        cout << iarr[i] << endl;
    }
    cout << "________________________" << endl;
    for (int i = 0; i < cn; i++)
    {
        cout << carr[i] << endl;
    }
}