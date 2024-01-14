#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

template <typename T>
class skup {
	vector<T> s;
public:
	skup() : s(T()) {}
	void dodaj(T n)
	{
		s.push_back(n);
	}
	void izbrisi()
	{
		s.pop_back();
	}
	bool get(T n)
	{
		if (count(s.begin(), s.end(), n)) return 1;
		else return 0;
	}
};

int main()
{
	skup <int> si;
	si.dodaj(1);
	si.dodaj(2);
	si.dodaj(3);
	si.dodaj(4);
	cout << si.get(3) << endl;
	si.izbrisi();
	cout << si.get(3) << endl;

}