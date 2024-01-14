#pragma once
#include <iostream>
#include <string>
#include <algorithm>
#include "Board.hpp"


class Player {
private:
	std::string name;
	Board players_board;
	Board opponents_board;
	int32_t cnt = 17;

public:
	
	Player(std::string name, Board &players_board, Board &opponents_board);
	
	Board& get_players_board();
	Board get_opponents_board();
	int32_t get_cnt();

	void setting_board();

	void shoot(Player &opponent, Player &player);
	void print_players_board();
	void print_opponents_board();
};




















