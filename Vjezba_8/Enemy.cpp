#include <iostream>
#include "Enemy.hpp"

Enemy::Enemy(std::string name, int health, int damage) {
	 
	if ((health < 0) || (damage < 0)) throw std::invalid_argument(" Must be more than zero");
	
	this->name = name;
	this->health = health;
	this->damage = damage;

}

void Enemy::attack() {
	std::cout << "Enemy made an attack!" << std::endl;
}

void Enemy::displayInfo() {
	std::cout << this->get_name()  << std::endl;
	std::cout << this->get_health() << std::endl;
	std::cout << this->get_damage() << std::endl;
}

std::string Enemy::get_name() {
	return this->name;
}

int Enemy::get_health() {
	return this->health;
}

int Enemy::get_damage() {
	return this->damage;
}

// BOSS
Boss::Boss(std::string name, int health, int damage, int damage_multiplier) {

	if ((health < 0) || (damage < 0) || (damage_multiplier < 0)) throw std::invalid_argument(" Must be more than zero");

	this->name = name;
	this->health = health;
	this->damage = damage;
	this->damage_multiplier = damage_multiplier;

}

std::string Boss::get_name() {
	return this->name;
}

int Boss::get_health() {
	return this->health;
}

int Boss::get_damage() {
	return this->damage;
}

int Boss::get_damage_multiplier() {
	return this->damage_multiplier;
}


void Boss::attack_calc() {
	int i = this->get_damage();
	damage_multiplier *= i;
}

void Boss::attack() {
	std::cout << "Enemy Boss made an attack!" << std::endl;
}

void Boss::displayInfo() {
	std::cout << "Name: " << this->get_name() << std::endl;
	std::cout << "Health: " << this->get_health() << std::endl;
	std::cout << "Damage: " << this->get_damage() << std::endl;
	std::cout << "Damage multiplier:" << this->get_damage_multiplier() << std::endl;
}

//MONSTER

Monster::Monster(std::string name, int health, int damage, std::string sposobnost) {
	
	if ((health < 0) || (damage < 0) || (sposobnost.empty() )) throw std::invalid_argument(" Must be more than zero");

	this->name = name;
	this->health = health;
	this->damage = damage;
	this->sposobnost = sposobnost;
}

void Monster::attack() {
	std::cout << "Enemy Monster made an attack!" << std::endl;
}

std::string Monster::get_name() {
	return this->name;
}

int Monster::get_health() {
	return this->health;
}

int Monster::get_damage() {
	return this->damage;
}

std::string Monster::get_sposobnost() {
	return this->sposobnost;
}

void Monster::displayInfo() {
	std::cout << "Name: " << this->get_name() << std::endl;
	std::cout << "Health: " << this->get_health() << std::endl;
	std::cout << "Damage: " << this->get_damage() << std::endl;
	std::cout << "Sposobnost: " << this->get_sposobnost() << std::endl;
}




