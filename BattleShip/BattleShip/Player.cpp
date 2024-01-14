#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_map>
#include "Player.hpp"
#include "Board.hpp"
#include "Cordinate.hpp"

int letterToNumber(char letter) {
	static const std::unordered_map<char, int> letterMap = {
		{'A', 0},
		{'B', 1},
		{'C', 2},
		{'D', 3},
		{'E', 4},
		{'F', 5},
		{'G', 6},
		{'H', 7}
	};

	letter = toupper(letter);
	
	auto it = letterMap.find(letter);
	if (it != letterMap.end()) {
		return it->second;
	}
	return -1;
}

Player::Player(std::string name, Board &board_s, Board &board_h) {
	this->name = name;
	this->players_board = players_board;
	this->opponents_board = board_h;
}

Board& Player::get_players_board() {
	return players_board;
}

Board Player::get_opponents_board() {
	return this->opponents_board;
}

int32_t Player::get_cnt() {
	return this->cnt;
}

void Player::setting_board() {
	Coordinates p1;
	Coordinates p2, p3, p4, p5;
	char direction;
	char c;
	std::cout << "Player is setting the ships!" << std::endl;
	std::cout << "\n" << std::endl;

	//Carrier
	while (1) {
		std::cout << "On what coordinates do you want to put the head of the Carrier? (example: ""A 4"")" << std::endl;
		std::cin >> c >> p1.y;
		std::cout << "\n" << std::endl;
		std::cout << "What direction do you want it to face? (h/v)" << std::endl;
		std::cin >> direction;

		p1.x = letterToNumber(c);

		
		if ((direction == 'h' && (p1.y + 4 > 7)) || (direction == 'v' && (p1.x + 4 > 7)))
		{
			std::cout << "Your input was out of bounds! Try again!" << std::endl;
		}
		else if ((p1.x >= 0) && (p1.x <= 7) && (p1.y >= 0) && (p1.y <= 7) && ((direction == 'h') || (direction == 'v'))) {
			std::cout << "\n" << "Good!" << std::endl;
			break;
		}
		else {
			std::cout << "Your input was incorrect! Try again!" << std::endl;
		}
	}
	this->players_board.set_players_board(p1.x, p1.y, direction, 5);
	
	std::cout << "\n" << std::endl;
	this->players_board.print_board();
	std::cout << "\n" << std::endl;

	//Battleship

	while (1) {
		std::cout << "On what coordinates do you want to put the head of the Battleship?" << std::endl;
		std::cin >> c >> p2.y;
		std::cout << "\n" << std::endl;
		std::cout << "What direction do you want it to face? (h/v)" << std::endl;
		std::cin >> direction;

		p2.x = letterToNumber(c);


		if ((direction == 'h' && (p2.y + 3 > 7)) || (direction == 'v' && (p2.x + 3 > 7)))
		{
			std::cout << "Your input was out of bounds! Try again!" << std::endl;
		}
		else if (this->players_board.check_for_overlap(p2.x, p2.y, direction, 4) == -1) {
			std::cout << "Your ships are overlaping! Try again!" << std::endl;
		}
		else if ((p2.x >= 0) && (p2.x <= 7) && (p2.y >= 0) && (p2.y <= 7) && ((direction == 'h') || (direction == 'v'))) {
			std::cout << "\n" << "Good!" << std::endl;
			break;
		}
		else {
			std::cout << "Your input was incorrect! Try again!" << std::endl;
		}
	}
	this->players_board.set_players_board(p2.x, p2.y, direction, 4);

	std::cout << "\n" << std::endl;
	this->players_board.print_board();
//
	//Cruiser
	while (1) {
		std::cout << "On what coordinates do you want to put the head of the Cruiser?" << std::endl;
		std::cin >> c >> p3.y;
		std::cout << "\n" << std::endl;
		std::cout << "What direction do you want it to face? (h/v)" << std::endl;
		std::cin >> direction;

		p3.x = letterToNumber(c);


		if ((direction == 'h' && (p3.y + 2 > 7)) || (direction == 'v' && (p3.x + 2 > 7)))
		{
			std::cout << "Your input was out of bounds! Try again!" << std::endl;
		}
		else if (this->players_board.check_for_overlap(p3.x, p3.y, direction, 3) == -1) {
			std::cout << "Your ships are overlaping! Try again!" << std::endl;
		}
		else if ((p3.x >= 0) && (p3.x <= 7) && (p3.y >= 0) && (p3.y <= 7) && ((direction == 'h') || (direction == 'v'))) {
			std::cout << "\n" << "Good!" << std::endl;
			break;
		}
		else {
			std::cout << "Your input was incorrect! Try again!" << std::endl;
		}
	}
	this->players_board.set_players_board(p3.x, p3.y, direction, 3);

	std::cout << "\n" << std::endl;
	this->players_board.print_board();

	//Submarine
	while (1) {
		std::cout << "On what coordinates do you want to put the head of the Submarine?" << std::endl;
		std::cin >> c >> p4.y;
		std::cout << "\n" << std::endl;
		std::cout << "What direction do you want it to face? (h/v)" << std::endl;
		std::cin >> direction;

		p4.x = letterToNumber(c);


		if ((direction == 'h' && (p4.y + 2 > 7)) || (direction == 'v' && (p4.x + 2 > 7)))
		{
			std::cout << "Your input was out of bounds! Try again!" << std::endl;
		}
		else if (this->players_board.check_for_overlap(p4.x, p4.y, direction, 3) == -1) {
			std::cout << "Your ships are overlaping! Try again!" << std::endl;
		}
		else if ((p4.x >= 0) && (p4.x <= 7) && (p4.y >= 0) && (p4.y <= 7) && ((direction == 'h') || (direction == 'v'))) {
			std::cout << "\n" << "Good!" << std::endl;
			break;
		}
		else {
			std::cout << "Your input was incorrect! Try again!" << std::endl;
		}
	}
	this->players_board.set_players_board(p4.x, p4.y, direction, 3);

	std::cout << "\n" << std::endl;
	this->players_board.print_board();

	//Destroyer
	while (1) {
		std::cout << "On what coordinates do you want to put the head of the Destroyer?" << std::endl;
		std::cin >> c >> p5.y;
		std::cout << "\n" << std::endl;
		std::cout << "What direction do you want it to face? (h/v)" << std::endl;
		std::cin >> direction;

		p5.x = letterToNumber(c);


		if ((direction == 'h' && (p5.y + 1 > 7)) || (direction == 'v' && (p5.x + 1 > 7)))
		{
			std::cout << "Your input was out of bounds! Try again!" << std::endl;
		}
		else if (this->players_board.check_for_overlap(p5.x, p5.y, direction, 2) == -1) {
			std::cout << "Your ships are overlaping! Try again!" << std::endl;
		}
		else if ((p5.x >= 0) && (p5.x <= 7) && (p5.y >= 0) && (p5.y <= 7) && ((direction == 'h') || (direction == 'v'))) {
			std::cout << "\n" << "Good!" << std::endl;
			break;
		}
		else {
			std::cout << "Your input was incorrect! Try again!" << std::endl;
		}
	}
	this->players_board.set_players_board(p5.x, p5.y, direction, 2);

	std::cout << "\n" << std::endl;
	this->players_board.print_board();

}

void Player::shoot(Player &opponent, Player &player) {
	Coordinates h1;
	char c;
	if (this->cnt == 0) {
		return;
	}

	while (1) {

		std::cout << "Choose where do you want to shoot!" << std::endl;
		std::cin >> c >> h1.y;
		h1.x = letterToNumber(c);

		if (h1.x >= 0 && h1.x <= 7 && h1.y >= 0 && h1.y <= 7) {
			break;
		}
		else {
			std::cout << "Your coordinates where out of bound! Try again!" << std::endl;
		}
	}

	if (opponent.get_players_board().check_if_hit(player.opponents_board, opponent.get_players_board(), h1.x, h1.y) == -1) {
		this->cnt--;
		shoot(opponent, player);
	}
}

void Player::print_players_board() {
	std::cout << "\n" << std::endl;
	std::cout << "Players board\n" << std::endl;
	this->players_board.print_board();
}

void Player::print_opponents_board() {
	std::cout << "\n" << std::endl;
	std::cout << "Opponents board\n" << std::endl;
	this->opponents_board.print_board();
}















