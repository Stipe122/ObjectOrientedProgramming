#include <iostream>
#include <string>

class Enemy {
protected:
	std::string name;
	int health;
	int damage;
public:
	Enemy() {};

	Enemy(std::string name, int health, int damage);
	virtual void attack() = 0;
	virtual void displayInfo() = 0;

	std::string get_name();
	int get_health();
	int get_damage();
};


class Boss : public Enemy {
protected:
	int damage_multiplier;
public:
	Boss(std::string name, int health, int damage, int damage_multiplier);

	void attack_calc();
	
	std:: string get_name();
	int get_health();
	int get_damage();
	int get_damage_multiplier();

	void attack();
	void displayInfo();
};

class Monster : public Enemy {
protected:
	std::string sposobnost;
public:
	Monster(std::string name, int health, int damage, std::string sposobnost);
	void attack();

	std::string get_name();
	int get_health();
	int get_damage();
	std::string get_sposobnost();
	void displayInfo();
};














