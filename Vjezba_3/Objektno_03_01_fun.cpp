#include <iostream>
#include "Objektno_03_01.hpp"
#include <algorithm>
#include <vector>

vector<int> izbaciElement(vector<int> vektor, int index) {
	vektor.erase(vektor.begin() + index);
	return vektor;
}

void unosVektor1(vector<int>& vektor, int size) {
	int el;
	cout << "Unesite elemente niza" << endl;
	for (int i = 0; i < size; i++) {
		cin >> el;
		vektor.push_back(el);
	}
};

void unosVektor2(vector<int>& vektor, int donjaGranica, int gornjaGranica) {
	int input;
	printf("Unesite elemente u intervalu [%d, %d] \n", donjaGranica, gornjaGranica);
	while ((input < gornjaGranica) && (input > donjaGranica)) {
		cin >> input;
		vektor.push_back(input);
	}
};

void ispisVektor(vector <int>& vektor) {
	cout << "Ispis vektora: " << endl;
	for (int i = 0; i < vektor.size(); i++) {
		cout << vektor.at(i) << endl;
	}
};



void sortVektor(vector<int>& vektor) {
	sort(vektor.begin(), vektor.end());
	
	int sum = 0;
	for (int i = 0; i < vektor.size(); i++) {
		sum += vektor.at(i);
	}

	cout << "sum:" << sum << endl;

	vektor.insert(vektor.begin(), 0);
	vektor.push_back(sum);
}