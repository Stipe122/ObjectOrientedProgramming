#include <iostream>
#include <string>
#include <algorithm>
#include "Board.hpp"

Board::Board() {
	
}

std::vector<std::vector<char>> Board::get_board() {
    return this->board;
}

int32_t Board::check_for_overlap(uint32_t x, uint32_t y, char d, uint32_t len) {
    if (d == 'h') {
        while (len != 0) {
            if (board[x][y] != '0') {
                return -1;
            }
            y++;
            len--;
        }
    }
    else {
        while (len != 0) {
            if (board[x][y] != '0') {
                return -1;
            }
            x++;
            len--;
        }
    }
    return 1;
}



void Board::set_players_board(uint32_t x, uint32_t y, char d, uint32_t len) {
    
    if (d == 'h') {
        while (len != 0) {
            board[x][y] = '1';
            y++;
            len--;
        }
    }
    else {
        while (len != 0) {
            board[x][y] = '1';
            x++;
            len--;
        }
    }
}

int32_t Board::check_if_hit(Board& players_opponents_board, Board& opponents_players_board, uint32_t x, uint32_t y) {
    if (opponents_players_board.board[x][y] == '1') {
        players_opponents_board.board[x][y] = 'x';
        opponents_players_board.board[x][y] = 'x';
        std::cout << "\n" << std::endl;
        std::cout << "Hit!" << std::endl;
        std::cout << "\n" << std::endl;
        return -1;
    }
    else {
        players_opponents_board.board[x][y] = '.';
        opponents_players_board.board[x][y] = '.';
        std::cout << "\n" << std::endl;
        std::cout << "Miss!" << std::endl;
        std::cout << "\n" << std::endl;
        return 0;
    }
}

void Board::print_board() {
    
    std::cout << "    0 1 2 3 4 5 6 7" << std::endl;
    std::cout << "\n";
    
    for (int i = 0; i < 8; i++) {
        std::cout << static_cast<char>('A' + i) << "   "; 

        for (int j = 0; j < 8; j++) {
            std::cout << board[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}























