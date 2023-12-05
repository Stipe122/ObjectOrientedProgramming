#include <iostream>
#include <string>
#pragma once

class Food {
private:
	std::string naziv;
	static int counter;

public:
	Food(std::string);

	void inc_counter();
	void dec_counter();
	void print_counter();

	friend int get_counter();

};

























