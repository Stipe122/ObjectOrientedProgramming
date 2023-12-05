#include <iostream>
#include "VirtualPet.hpp"
#include<vector>
#pragma once

class Owner {
private:
	
	std::string ime;
	int br_ljubimaca = 0;
	std::vector <VirtualPet> Ljubimci;
	int br_hranjenja = 100;
	int br_igranja = 100;


public:
	Owner(std::string ime);
	Owner(const Owner &other);
	~Owner();

	std::string get_ime();

	void set_ime(std::string ime);

	VirtualPet max_sreca();

	void add_pet(VirtualPet Pet);
	void biraj();

	int get_br_hranjenja();
	int get_br_igranja();



};
















