#include "Food.hpp"

int Food::counter = 0;

Food::Food(std::string) {
	this->naziv = naziv;
}

void Food::inc_counter() {
	counter++;
}

void Food::dec_counter() {
	counter--;
}

int get_counter() {
	return Food::counter;
}

void Food::print_counter() {
	std::cout << "Counter: " << get_counter() << std::endl;
}
























