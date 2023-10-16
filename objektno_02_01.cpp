#include<iostream>

using namespace std;


void min_max(int* niz, int& max, int& min, int len) {
	
	int k = 0;
	min = niz[0];
	max = niz[0];

	for (k ; k < len ; k++) {
		if (niz[k] < min)
			min = niz[k];
		if (niz[k] > max)
			max = niz[k];
	}

	
}

int main() {
	int max, min;
	int len;
	int i=0;

	cout << "Unesi broj: ";
	cin >> len;

		
	int* niz = new int[len];

	for (i; i < len; i++) {

		cout << "Unesite broj: ";
		cin >> niz[i];
	}

	min_max(niz, max, min, len);

	cout << min << " " << max << endl;

	return 0;
}