#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <sstream>
#include <cstring>
#include "Objektno_04.hpp"
using namespace std;


int main()
{/*
	// 1.
	string str = "Ja bih, ako ikako mogu, ovu recenicu napisala ispravno. ako ikako mogu.";

	string substr = "mogu";

	int res = zad1(str, substr);

	cout << res << endl;
	
	// 2.
	string str2 = "Ja bih  , ako ikako mogu ,  ovu recenicu napisala ispravno. ";

	string res2 = "";
	res2 = zad2(str2);

	cout << res2 << endl;
	
	
	// 3.

	int n = 3;
	vector<string> vektor(n);
	zad3(vektor);
	*/
	
	// 4
	vector<string>recenice = { "What time is it?" };

	int randInt;

	srand(time(0));
	randInt = rand() % recenice.size();

	cout << randInt << endl;
	string novaRecenica = "";
	piglatin(recenice[randInt]); 
}