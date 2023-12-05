#include "VirtualPet.hpp"

int VirtualPet::get_sreca() {
	return this->sreca;
}

void VirtualPet::jedi() {
	if (budnost == false) {
		return;
	}
		
	
	if (glad == MIN_GLAD) {
		spavaj();
	}
	else {
		glad--;
		sreca++;
	}
}

void VirtualPet::spavaj() {
	budnost = false;
}

void VirtualPet::igranje() {
	if (budnost == false) {
		return;
	}

	if (sreca == MAX_SRECA) {
		glad++;
	}
	else {
		sreca++;
		glad++;
	}
}

VirtualPet::VirtualPet(std::string ime, std::string vrsta) {
	this->ime = ime;
	this->vrsta = vrsta;
}

VirtualPet::~VirtualPet() {

}

bool VirtualPet::operator== (VirtualPet const& other) {
	return ((this->ime == other.ime) && (this->vrsta == other.vrsta)
		&& (this->sreca == other.sreca) && (this->budnost == other.budnost));
}

bool VirtualPet::operator!=(VirtualPet const& other) {
	return ((this->ime != other.ime) || (this->vrsta != other.vrsta)
		|| (this->sreca != other.sreca) || (this->budnost != other.budnost));
}

VirtualPet VirtualPet::operator=(const VirtualPet& other) {
	VirtualPet x(other.ime,other.vrsta);
	return x;
}

int VirtualPet::operator++(int) {
	return glad--;
}

int VirtualPet::operator++() {
	return --glad;
}

bool VirtualPet::operator<(VirtualPet const& other) {
	return(this->sreca < other.sreca);
}

bool VirtualPet::operator>(VirtualPet const& other) {
	return(this->sreca > other.sreca);
}

bool VirtualPet::operator<=(VirtualPet const& other) {
	return(this->sreca <= other.sreca);
}

bool VirtualPet::operator>=(VirtualPet const& other) {
	return(this->sreca >= other.sreca);
}

std::ostream& operator<<(std::ostream& os, const VirtualPet & pet) {

	os << "Ime: " << pet.ime << std::endl 
		<< "Vrsta: "<< pet.vrsta << std::endl
		<< "Sreca:  " << pet.sreca << std::endl 
		<< "Budnost: " << pet.budnost << std::endl;
	return os;
}















