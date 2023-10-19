
#include "Objektno_02_03.hpp"


void MyVector::vector_new(size_t sz)
{
    arr = new int[sz];
    if (!arr)
        return;
    capacity = sz;
    size = sz;
}
void MyVector::vector_delete()
{
    delete[] arr;
    size = 0;
    capacity = 0;
    std::cout << "Array has been deleted." << std::endl;
}
void MyVector::vector_push_back(int n)
{
    if (capacity > size)
        arr[size++] = n;
    else if (capacity == 0)
    {
        capacity = 1;
        size = 1;
        int* temp_arr, * temp_p;
        temp_arr = new int[capacity];
        if (!temp_arr)
            return;
        temp_arr[0] = n;
        temp_p = arr;
        arr = temp_arr;
        delete[] temp_p;
    }
    else
    {
        int i;
        int* temp_arr, * temp_p;
        temp_arr = new int[capacity * 2];
        if (!temp_arr)
            return;
        for (i = 0; i < capacity; i++)
        {
            temp_arr[i] = arr[i];
        }
        size = i;
        temp_arr[size] = n;
        temp_p = arr;
        arr = temp_arr;
        delete[] temp_p;
    }
    capacity = size * sizeof(int);
}
void MyVector::vector_pop_back()
{
    arr[size--];
    capacity = size * sizeof(int);
}
int& MyVector::vector_front()
{
    return arr[0];
}
int& MyVector::vector_back()
{
    return arr[size - 1];
}
size_t MyVector::vector_size()
{
    return size;
}


void MyVector::print_vector()
{
    for (size_t i = 0; i < vector_size(); ++i)
        std::cout << arr[i] << " ";
    std::cout << std::endl;
}