#include <iostream>
#include <fstream>
#include <string>

int main()
{
	std::fstream plik;
	std::string command;
	char letter;
	std::string output = "";
	int dl_hasla = 0;
	std::string last_command;
	int ilosc = 1;
	int max_ilosc = 0;
	std::string max_command;
	std::string haslo;


	plik.open("task_07_instrukcje.txt", std::ios::in);

	if (plik.is_open()) {
		std::cout << "Plik otwarty!" << std::endl;
	}

	for (int i = 1; i <= 2000; i++) {
		plik >> command >> letter;
		std::cout << command << " " << letter << std::endl;
		if (command == "DOPISZ") {
			dl_hasla += 1;
			haslo += letter;
		}
		else if (command == "USUN") {
			dl_hasla -= 1;
			haslo.pop_back();
		}
		else if (command == "ZMIEN") {
			haslo.pop_back();
			haslo += letter;
		}
		else if (command == "PRZESUN") {
			for (int j = 0; j < haslo.length(); j++) {
				if (haslo[j] == (letter)) {
					haslo[j] = (haslo[j] - 'A' + 1) % 26 + 'A';
					break;
				}
			}
		}




		if (command == last_command) {
			ilosc++;
		}
		else
		{
			if (ilosc > max_ilosc) {

				max_ilosc = ilosc;
				max_command = last_command;
			}
			ilosc = 1;
			last_command = command;
		}

	}

	int freq[26] = {0};

	for (char c : output) {
		if (isalpha(c)) {
			freq[tolower(c) - 'a']++;
		}
	}

	int max_freq = 0;
	char most_freq_letter;
	for (int i = 0; i < 26; i++) {
		if (freq[i] > max_freq) {
			max_freq = freq[i];
			most_freq_letter = 'a' + i;
		}
	}
	





	std::cout << haslo << std::endl;
	std::cout << "Dlugosc hasla: " << dl_hasla << std::endl;
	std::cout << max_command << std::endl;
	std::cout << max_ilosc << std::endl;
	std::cout << "Podpunkt 3: litera:" << most_freq_letter << ", ilosc: " << max_freq << std::endl;
	std::cout << output << std::endl;










	plik.close();
}