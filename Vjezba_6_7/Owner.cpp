#include "Owner.hpp"
#include <random>
Owner::Owner(std::string ime) {
	this->ime = ime;
}

void Owner::set_ime(std::string ime) {
		this->ime = ime;
}

std::string Owner::get_ime() {
	return this->ime;
}

int Owner::get_br_hranjenja() {
	return this->br_hranjenja;
}

int Owner::get_br_igranja() {
	return this->br_igranja;
}

Owner::Owner(const Owner& other) {
	ime = other.ime;
	br_ljubimaca = other.br_ljubimaca;
	Ljubimci = other.Ljubimci;
	br_hranjenja = other.br_hranjenja;
	br_igranja = other.br_igranja;
}

Owner::~Owner() {

}

void Owner::add_pet(VirtualPet Pet) {
	Ljubimci.push_back(Pet);
	br_ljubimaca++;
}

void Owner::biraj() {
	
		for (VirtualPet& ljubimac : Ljubimci) {
			if ((br_hranjenja != 0) && (br_igranja != 0)) {

				std::random_device r;
				std::default_random_engine e1(r());
				std::uniform_int_distribution<int> uniform_dist(1, 2);
				int k = uniform_dist(e1);

				if (k == 1) {
					ljubimac.igranje();
					br_igranja--;
				}
				else {
					ljubimac.jedi();
					br_hranjenja--;
				}
			}
			else if ((br_hranjenja != 0) && (br_igranja == 0)) {
				ljubimac.jedi();
				br_hranjenja--;
			}
			else if ((br_hranjenja == 0) && (br_igranja != 0)) {
				ljubimac.igranje();
				br_igranja--;
			}
	}
}

VirtualPet Owner::max_sreca() {
	VirtualPet sr_ljub = Ljubimci.at(0);

	for (VirtualPet ljubimac : Ljubimci) {
	
		if (sr_ljub.get_sreca() < ljubimac.get_sreca()) {
			sr_ljub = ljubimac;
		}
	}
	return sr_ljub;
}



















