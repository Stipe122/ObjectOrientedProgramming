#pragma once
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

class Board {
private:
	std::vector<std::vector<char>> board{
		{'0','0','0','0','0','0','0','0'},
		{'0','0','0','0','0','0','0','0'},
		{'0','0','0','0','0','0','0','0'},
		{'0','0','0','0','0','0','0','0'},
		{'0','0','0','0','0','0','0','0'},
		{'0','0','0','0','0','0','0','0'},
		{'0','0','0','0','0','0','0','0'},
		{'0','0','0','0','0','0','0','0'}
	};

public:
	Board();
	std::vector<std::vector<char>> get_board();

	void set_players_board(uint32_t x, uint32_t y, char d, uint32_t len);

	void print_board();

	int32_t check_for_overlap(uint32_t x, uint32_t y, char d, uint32_t len);

	int32_t check_if_hit(Board &players_opponents_board, Board &opponents_players_board, uint32_t x, uint32_t y);
};























