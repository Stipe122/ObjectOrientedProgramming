#include <iostream>
#include "Objektno_02_03.hpp"
using namespace std;



int main()
{

    MyVector mv;

    mv.vector_new(5);

    int m;
     
    std::cout << "Unesi element: " << endl;
    //Ctrl+z za kraj unosa

    while (std::cin >> m)
        mv.vector_push_back(m);


    std::cout << "size " << mv.vector_size() << endl;
    std::cout << "first element " << mv.vector_front() << endl;
    std::cout << "last element " << mv.vector_back() << endl;
    mv.print_vector();

    std::cout << "removing last element" << endl;
    mv.vector_pop_back();
    mv.print_vector();

    std::cout << "capacity " << mv.capacity << endl;

    mv.vector_delete();
}