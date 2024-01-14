#include <iostream>
#include <string>
#include <algorithm>
#include <limits>
#include "Board.hpp"
#include "Player.hpp"

int main() {

		std::cout << R"(
	__________         __    __  .__                .__    .__              
	\______   \_____ _/  |__/  |_|  |   ____   _____|  |__ |__|_____  ______
	 |   _|  _/\__  \\   __\   __\  | _/ __ \ /  ___/  |  \|  \____ \/  ___/
	 |    |   \ / __ \|  |  |  | |  |_\  ___/ \___ \|   Y  \  |  |_> >___ \ 
	 |______  /(____  /__|  |__| |____/\___  >____  >___|  /__|   __/____  >
			\/      \/                     \/     \/     \/   |__|       
		)";
	
	std::cout << "\n" << "\n" << std::endl;

	Board players_board1;
	Board players_board2;
	Board opponents_board1;
	Board opponents_board2;

	Player Vavkan("Vavkan", players_board1, opponents_board1);
	Player Polic("Polic", players_board2, opponents_board2);

	//postavljanje brodova

	Vavkan.setting_board();
	Polic.setting_board();

	//pocetak igre
	int x;
	std::cout << "Player1 is starting!" << std::endl;
	std::cout << "\n" << std::endl;

	while (1) {
		x = 0;
		
		while (1) {
			
			std::cout << "Player1" << std::endl;
			std::cout << "\n" << std::endl;
			std::cout <<	"Type '1' to see your board\n" <<
							"Type '2' to see opponents board\n" <<
							"Type '3' to shoot\n" << std::endl;
			std::cin >> x;

			if (std::cin.fail()) {
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cout << "Invalid input! Try again!" << std::endl;
				std::cout << "\n" << std::endl;
			}
			else if (x == 1) {
				Vavkan.print_players_board();
			}
			else if (x == 2) {
				Vavkan.print_opponents_board();
			}
			else if (x == 3) {
				Vavkan.shoot(Polic, Vavkan);
				break;
			}
			else {
				std::cout << "Invalid input! Try again!" << std::endl;
				std::cout << "\n" << std::endl;
				
			}

		}

		if (Vavkan.get_cnt() == 0) {
			std::cout << "GAME OVER!" << std::endl;
			std::cout << "\n" << std::endl;
			std::cout << "Player1 won!" << std::endl;
			break;
		}

		x = 0;
		while (1) {
			x = 0;

			std::cout << "\n" << std::endl;
			std::cout << "Player2" << std::endl;
			std::cout << "\n" << std::endl;
			std::cout <<	"Type '1' to see your board\n" <<
							"Type '2' to see opponents board\n" <<
							"Type '3' to shoot\n" << std::endl;
			std::cin >> x;

			if (std::cin.fail()) {
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cout << "Invalid input! Try again!" << std::endl;
				std::cout << "\n" << std::endl;
			}
			else if (x == 1) {
				Polic.print_players_board();
			}
			else if (x == 2) {
				Polic.print_opponents_board();
			}
			else if (x == 3) {
				Polic.shoot(Vavkan, Polic);
				break;
			}
			else {
				std::cout << "Invalid input! Try again!" << std::endl;
				std::cout << "\n" << std::endl;
			}

		}

		if (Polic.get_cnt() == 0) {
			std::cout << "GAME OVER!" << std::endl;
			std::cout << "\n" << std::endl;
			std::cout << "Player2 won!" << std::endl;
			break;
		}
	}


	return 0;
}




















