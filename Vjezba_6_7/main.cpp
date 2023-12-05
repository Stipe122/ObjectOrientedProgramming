#include <iostream>
#include "Owner.hpp"
#include "VirtualPet.hpp"
#include "Food.hpp"

int main() {
	Owner Miran("Miran");
	Owner Mate("Mate");

	VirtualPet Kroki("Kroki", "zaba");
	VirtualPet Foni("Foni", "ribica");
	VirtualPet Bubi("Bubi", "pas");
	VirtualPet Kiki("Kiki", "macka");

	Miran.add_pet(Kroki);
	Miran.add_pet(Foni);

	Mate.add_pet(Bubi);
	Mate.add_pet(Kiki);

	Owner Banda = Miran;
	Banda.set_ime("Banda");

	std::vector <Owner> vekt_Owner = { Miran, Mate, Banda };

	int sum = Miran.get_br_igranja() + Miran.get_br_hranjenja();

	for (int k=0; k < sum; k++) {
		for (Owner& vlanik : vekt_Owner)
			vlanik.biraj();
	}

	size_t j = 0;
	for (size_t i = 0; i < vekt_Owner.size(); i++) {
		if (vekt_Owner.at(j).max_sreca().get_sreca() < vekt_Owner.at(i).max_sreca().get_sreca()) {
			j = i;
		}
	}

	std::cout << vekt_Owner.at(j).get_ime() << std::endl;

	for (Owner vlasnik : vekt_Owner) {
		std::cout << vlasnik.get_ime() << ": " << vlasnik.max_sreca().get_sreca() << std::endl;
	}

	Food Keksi("Keksi");
	Food Hrana("Hrana");

	Keksi.inc_counter();
	Keksi.inc_counter();
	Hrana.inc_counter();

	Keksi.print_counter();
	
	if (Kroki == Foni) {
		std::cout << "Isti su" << std::endl;
	}
	else if (Kroki != Foni) {
		std::cout << "Nisu isti" << std::endl;
	}

	VirtualPet Vavkan = Bubi;

	Kroki++;
	++Bubi;

	if (Kroki < Foni) {
		std::cout << "Sporki je sretniji" << std::endl;
	}
	else if (Kroki > Foni) {
		std::cout << "Miroslav je sretniji" << std::endl;
	}


	std::cout << Kroki << std::endl;



	return 0;
}
























