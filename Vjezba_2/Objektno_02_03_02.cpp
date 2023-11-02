#include "Objektno_02_03.hpp"
#include <iostream>

void MyVector::vector_new(size_t sz)
{
	capacity = sz;
	arr = new int[capacity];
	size = 0;
}
void MyVector::vector_delete()
{
	delete[] arr;
	size = 0;
	capacity = 0;
}
void MyVector::vector_push_back(int n)
{
	if (size == capacity) {
		int* temp = arr;
		capacity = capacity * 2;
		arr = new int[capacity];
		for (int i = 0; i < size; i++) {
			arr[i] = temp[i];
		}
		delete[]temp;
	}
	arr[size] = n;
	size++;
}
void MyVector::vector_pop_back()
{
	if ((size - 1) >= 0) {
		arr[size--] = 0;
	}
}
int& MyVector::vector_front()
{
	if ((size - 1) >= 0) {
		return arr[0];
	}
}
int& MyVector::vector_back()
{
	if ((size - 1) >= 0) {
		return arr[size - 1];
	}
}
size_t MyVector::vector_size()
{
	return size;
}


void MyVector::print_vector()
{
	for (size_t i = 0; i < size; ++i)
		std::cout << arr[i] << " ";
	std::cout << std::endl;
}