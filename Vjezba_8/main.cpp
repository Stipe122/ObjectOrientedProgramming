#include <iostream>
#include "Enemy.hpp"

int main() {

	try {
		Boss Mile("Mile", 5, 2, 5);
		Boss Marko("Marko", 7, 3, 9);
		Monster Ghost("Ghost", 8, 9, "Sikira");
		Monster Skeleton("Skeleton", 8, 2, "Mac");

		Mile.attack();
		Ghost.attack();

		Ghost.displayInfo();
		Mile.displayInfo();
	}
	catch(std::invalid_argument const& ex) {
		std::cout << "Podaci nisu ispravni  " << ex.what() << std::endl;
	}


	return 0;
}