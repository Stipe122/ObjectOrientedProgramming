#include <iostream>
#include <string>
#pragma once

constexpr int MAX_GLAD = 10;
constexpr int MIN_GLAD = 0;
constexpr int MAX_SRECA = 10;
constexpr int MIN_SRECA = 0;

class VirtualPet{
private:
	std::string ime;
	std::string vrsta;
	int glad = 5;
	int sreca = 0;
	bool budnost = true;
public:
	int get_sreca();
	
	void jedi(); 
	void spavaj();
	void igranje();
	VirtualPet(std::string ime, std::string vrsta);
	~VirtualPet();

	bool operator==(VirtualPet const& other);
	bool operator!=(VirtualPet const& other);

	VirtualPet operator=(VirtualPet const& other);

	int operator++();
	int operator++(int);


	bool operator<(VirtualPet const& other);
	bool operator>(VirtualPet const& other);
	bool operator<=(VirtualPet const& other);
	bool operator>=(VirtualPet const& other);

	friend std::ostream& operator<<(std::ostream& os, const VirtualPet & pet);
};


















