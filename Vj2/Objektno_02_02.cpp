#include <iostream>

int& funkcija(int* niz, int n) {


	return ++niz[n];
}

int main() {

	int niz[] = {1, 2, 3, 4, 5};

	int n = 3;

	int& a = funkcija(niz, n);

	std::cout << a;

	return 0;
}

















