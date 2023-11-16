#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <random>

class Karta {
private:
	int broj;
	std::string zog;
public:
	int get_broj() { return this->broj; }
	std::string get_zog() { return this->zog; }
	void set_karta(int br, std::string z) {
		this->broj = br;
		this->zog = z;
	}
	};

class Igrac {
private:
	std::string ime;
	int broj_bodova = 0;
	std::vector <Karta> ruka;
	std::vector<Karta> napolitana;
	std::vector<std::string>zogovi;
	Karta napoli1;
	Karta napoli2;
	Karta napoli3;

public:
	void set_ime(std::string ime_igraca) {
		this->ime = ime_igraca;
	}
	void print_bodovi() {
		std::cout << broj_bodova << std::endl;
	}
	std::vector <Karta> set_ruka(std::vector <Karta> deck) {
		for (int i = 0; i < 10; i++) {
			ruka.push_back(deck.at(i));
		}
		deck.erase(deck.begin(), deck.begin() + 9);
		return deck;
	}
	void print_ruka() {
		for (int j = 0; j < 10; j++) {
			std::cout << ruka.at(j).get_broj() << ruka.at(j).get_zog() << std::endl;
		}
		 
	}

	void akuze() {
		int cnt1 = 0;
		int cnt2 = 0;
		int cnt3 = 0;

		for (int k = 0; k < ruka.size(); k++) {
			if (ruka.at(k).get_broj() == 1){
				cnt1++;
				napoli1.set_karta(ruka.at(k).get_broj(), ruka.at(k).get_zog());
				napolitana.push_back(napoli1);
			}
			if (ruka.at(k).get_broj() == 2){
				cnt2++;
				napoli2.set_karta(ruka.at(k).get_broj(), ruka.at(k).get_zog());
				napolitana.push_back(napoli2);
			}
			if (ruka.at(k).get_broj() == 3){
				cnt3++;
				napoli3.set_karta(ruka.at(k).get_broj(), ruka.at(k).get_zog());
				napolitana.push_back(napoli3);
			}
		}
		
		int bata1 = 0;
		int bata2 = 0;
		int bata3 = 0;
		int kupa1 = 0;
		int kupa2 = 0;
		int kupa3 = 0;
		int dinara1 = 0;
		int dinara2 = 0;
		int dinara3 = 0;
		int spada1 = 0;
		int spada2= 0;
		int spada3 = 0;
		for (int i = 0; i < napolitana.size(); i++) {
			if (napolitana.at(i).get_broj() == 1 && napolitana.at(i).get_zog() == "bata")
				bata1++;

			if (napolitana.at(i).get_broj() == 1 && napolitana.at(i).get_zog() == "kupa")
				kupa1++;

			if (napolitana.at(i).get_broj() == 1 && napolitana.at(i).get_zog() == "dinara")
				dinara1++;

			if (napolitana.at(i).get_broj() == 1 && napolitana.at(i).get_zog() == "spada")
				spada1++;

			if (napolitana.at(i).get_broj() == 2 && napolitana.at(i).get_zog() == "bata")
				bata2++;

			if (napolitana.at(i).get_broj() == 2 && napolitana.at(i).get_zog() == "kupa")
				kupa2++;

			if (napolitana.at(i).get_broj() == 2 && napolitana.at(i).get_zog() == "dinara")
				dinara2++;

			if (napolitana.at(i).get_broj() == 2 && napolitana.at(i).get_zog() == "spada")
				spada2++;

			if (napolitana.at(i).get_broj() == 3 && napolitana.at(i).get_zog() == "bata")
				bata3++;

			if (napolitana.at(i).get_broj() == 3 && napolitana.at(i).get_zog() == "kupa")
				kupa3++;

			if (napolitana.at(i).get_broj() == 3 && napolitana.at(i).get_zog() == "dinara")
				dinara3++;

			if (napolitana.at(i).get_broj() == 3 && napolitana.at(i).get_zog() == "spada")
				spada3++;

		}
		if ((bata1 == 1 && bata2 == 1 && bata3 == 1) || (spada1 == 1 && spada2 == 1 && spada3 == 1) || (dinara1 == 1 && dinara2 == 1 && dinara3 == 1) || (kupa1 == 1 && kupa2 == 1 && kupa3 == 1))
			broj_bodova =broj_bodova + 3;

	

		
		if (cnt1 == 3)
			broj_bodova = broj_bodova + 3;;
		if (cnt2 == 3)
			broj_bodova = broj_bodova + 3;;
		if (cnt3 == 3)
			broj_bodova = broj_bodova + 3;;
		if (cnt1 == 4)
			broj_bodova += 4;
		if (cnt2 == 4)
			broj_bodova += 4;
		if (cnt3 == 4)
			broj_bodova += 4;


	}
	


};

class Deck{
private:
	std::vector <Karta> deck;
	Karta k;
	std::vector <int> brojevi { 1,2,3,4,5,6,7,11,12,13 };
	std::vector <std::string> zogovi{ "bata", "kupa", "dinara", "spada" };
public:
	std::vector <Karta> get_deck() { return this->deck; }
	void make_deck() {
		for (int i = 0; i < zogovi.size(); i++) {
			for (int j = 0; j < brojevi.size(); j++) {
				k.set_karta(brojevi.at(j), zogovi.at(i));
				deck.push_back(k);
			}
		}
	}
	void shuffle() {

		std::random_device rd;
		std::mt19937 g(rd());

		std::shuffle(deck.begin(), deck.end(), g);
	}
};






















