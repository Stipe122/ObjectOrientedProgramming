#include <iostream>
#include <cmath>

using namespace std;

template<typename T>
class point {
	T x;
	T y;
public:
	point(T x, T y) { this->x = x; this->y = y; }
	friend double operator-(point p1, point p2)
	{
		return sqrt((p2.x - p1.x) * (p2.x - p1.x) + (p2.y - p1.y) * (p2.y - p1.y));
	}
	friend ostream& operator<<(ostream& os, point& p)
	{
		os << "(" << p.x << "," << p.y << ")";
		return os;
	}
};

int main()
{
	point <int> p1(2, 3), p2(3, 4);
	cout << " udaljenost tocaka " << p1 << " i " << p2 << " je " << p1 - p2 << endl;
}