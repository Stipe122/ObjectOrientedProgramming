#include <iostream>
#include <algorithm>
#include <vector>
#include "Objektno_03_01.hpp"
using namespace std;



int main()
{
	vector<int> vektor;

	cout << "Unesite velicinu vektora1: " << endl;
	int size1;
	cin >> size1;

	cout << "Unesite velicinu vektora2: " << endl;
	int size2;
	cin >> size2;

	vector<int>vektor1;
	vector<int>vektor2;

	unosVektor1(vektor1, size1);
	unosVektor1(vektor2, size2);
	unosVektor2(vektor1, 3, 7);
	ispisVektor(vektor1);
	ispisVektor(vektor2);

	vector<int>noviVektor;

	for (int i = 0; i < size1; i++)
	{
		bool inSecond = false;
		for (int j = 0; j < size2; j++) {
			if (vektor1.at(i) == vektor2.at(j)) {
				inSecond = true;
			}
		}
		if (inSecond == false)
		{
			noviVektor.push_back(vektor1.at(i));
		}
	}
	ispisVektor(noviVektor);

	/*
	3. Koristeći STL funkcije sortirajte vektor,
	ubacite 0 ispred najmanjeg elementa,
	te sumu svih elemenata iza najvećeg elementa.
	*/

	sortVektor(vektor1);
	ispisVektor(vektor1);


	// 4
	vektor1 = izbaciElement(vektor1, 1);
	ispisVektor(vektor1);
}














