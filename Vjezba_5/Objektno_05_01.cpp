#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "Objektno_05.hpp"


int main() {
	int br_igraca = 0;
	int i = 0;
	std::string ime_igraca;
	std::vector <std::string> Igraci;
	Deck spil;
	std::vector <Karta> sve_karte;

	Igrac igr1;
	Igrac igr2;
	Igrac igr3;
	Igrac igr4;
	std::vector <Igrac> Igraci_t{ igr1, igr2, igr3, igr4 };


	spil.make_deck();
	spil.shuffle();
	sve_karte = spil.get_deck();

	while ((br_igraca != 2) && (br_igraca != 4)) {
		std::cout << "Unesite broj igraca: " << std::endl;
		std::cin >> br_igraca;
	}


	for (i; i < br_igraca; i++) {

		std::cout << "Unesite ime igraca: " << std::endl;
		std::cin >> ime_igraca;
		Igraci.push_back(ime_igraca);
	}

	if (br_igraca == 2) {
		for (int n = 0; n < 2; n++) {
			Igraci_t.at(n).set_ime(Igraci.at(n));
			sve_karte = Igraci_t.at(n).set_ruka(sve_karte);
		}
	}
	else if (br_igraca == 4) {
		for (int n = 0; n < 4; n++) {
			Igraci_t.at(n).set_ime(Igraci.at(n));
			sve_karte = Igraci_t.at(n).set_ruka(sve_karte);
		}
	}


	std::cout << "\n";


	if (br_igraca == 2) {
		for (int n = 0; n < 2; n++) {
			Igraci_t.at(n).print_ruka();
			std::cout << "\n";
		}
	}
	else if (br_igraca == 4) {
		for (int l = 0; l < 4; l++) {
			Igraci_t.at(l).print_ruka();
			std::cout << "\n";
		}
	}

	if (br_igraca == 2) {
		for (int n = 0; n < 2; n++) {
			Igraci_t.at(n).akuze();
		}
	}
	else if (br_igraca == 4) {
		for (int l = 0; l < 4; l++) {
			Igraci_t.at(l).akuze();
		}
	}

	if (br_igraca == 2) {
		for (int n = 0; n < 2; n++) {
			Igraci_t.at(n).print_bodovi();
			std::cout << "\n";
		}
	}
	else if (br_igraca == 4) {
		for (int l = 0; l < 4; l++) {
			Igraci_t.at(l).print_bodovi();
			std::cout << "\n";
		}
	}



	return 0;
}














