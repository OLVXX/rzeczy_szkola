#include <iostream>
#include <string>
#include <fstream>



int main()
{


	std::fstream instrukcje;
	std::fstream wynik;

	instrukcje.open("./zadanie_09_mecz.txt", std::ios::in);
	wynik.open("./wyniki1.txt", std::ios::out);





	std::string wins;
	char last_win;
	char current_win;




	instrukcje >> wins;
	last_win = wins[0];
	int roz = 0;
	int win_a = 0;
	int win_b = 0;
	int streak_current = 0;
	int h_streak_a = 0;
	int h_streak_b = 0;
	int total_highest_streak = 0;
	int passa_il = 0;
	int first_set = 0;
	std::string msg;






	for (int i = 0; i < wins.size(); ++i) {
		if (i == 0) {
			last_win = wins[i];
		}
		else {
			last_win = wins[i - 1];
		}
		current_win = wins[i];
		if (current_win == 'A') {
			win_a += 1;
		}
		else if (current_win == 'B') {
			win_b += 1;
		}



		char new_game = wins[i + 1];

		if (last_win == current_win) {
			streak_current += 1;
		}
		else {
			roz += 1;
			streak_current = 1;
		}




		if (streak_current >= 10 && current_win != new_game) {
			if (last_win == 'A') {
				if (h_streak_a < streak_current) {
					h_streak_a = streak_current;
				}
			}
			else {
				if (h_streak_b < streak_current) {
					h_streak_b = streak_current;
				}
			}
			passa_il += 1;
		}






		if (win_a >= 1000 && win_b <= win_a - 3 && first_set == 0) {
			wynik << "Subtask_2 " << "Wygrala druzyna A - wynik " << win_a << " : " << win_b << std::endl;
			if (h_streak_a < streak_current) {
				std::cout << "CHECK1" << std::endl;
				h_streak_a = streak_current;
			}
			first_set = 1;






		}
		else if (win_b >= 1000 && win_a <= win_b - 3 && first_set == 0) {
			wynik << "Wygrala druzyna B - wynik " << win_a << " : " << win_b << std::endl;
			if (h_streak_b < streak_current) {
				std::cout << "CHECK2" << std::endl;
				h_streak_b = streak_current;
			}
			first_set = 1;
		}
	}



	char highest_streak_team = ' ';






	if (h_streak_a > h_streak_b) {
		highest_streak_team = 'A';
		total_highest_streak = h_streak_a;
	}




	else if (h_streak_a < h_streak_b) {
		highest_streak_team = 'B';
		total_highest_streak = h_streak_b;
	}
	else {
		std::cout << "sorry ale nie dziala " << h_streak_a << " : " << h_streak_b << std::endl;
	}

	wynik << "Subtask_1 " << roz << std::endl;

	wynik << "Subtask_3 " << passa_il << " " << highest_streak_team << " " << total_highest_streak << std::endl;
	instrukcje.close();
	wynik.close();






	return 0;
}