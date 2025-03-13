#include <iostream>
#include <cstring>
#include <vector>
#include <string>
#include <set>



bool is_upper_case(char literka);
bool is_special_character(char literka);
bool is_string_valid(std::string str);
void encryption(std::string str, int shift);
void decryption(std::string str, int shift);





int main()
{

	std::string ciag;
	int ile, cho;

	std::cout << "1. Szyfrowanie\n";
	std::cout << "2. Odszyfrowywanie\n";

	std::cin >> cho;




	std::cout << "Podaj o ile przesunac znaki w szyfrze";
	std::cin >> ile;

	std::cout << "Podaj ciąg znaków ";
	std::cin.ignore();
	std::getline(std::cin, ciag);




	switch (cho) {
	case 1:
		if (is_string_valid) {
			encryption(ciag, ile);
		}
		else {
			std::cout << "Niepoprawny ciąg znaków\n";
			return 0;
		}


		break;

	case 2:
		if (is_string_valid) {
			decryption(ciag, ile);
		}
		else {
			std::cout << "Niepoprawny ciąg znaków\n";
			return 0;
		}
		break;

	}
}

bool is_upper_case(char literka) {
	if ((literka >= 65 && literka <= 90)) {

		return true;
	}
	else {

		return false;
	}
}




bool is_special_character(char literka) {

	if (literka == ' ' || literka == '/n') {
		return true;
	}
	else {

		return false;
	}
}




bool is_string_valid(std::string str) {

	for (int i = 0; i < str.size(); i++) {
		if (is_special_character(str[i])) {
			continue;
		}

		if (is_upper_case(str[i]) == false) {
			return false;
		}


	}

	return true;
}





void encryption(std::string str, int shift) {

	std::string temp2 = str;


	for (int i = 0; i < str.size(); i++) {

		if (is_special_character(str[i])) {
			continue;
		}

		temp2[i] = (str[i] - 'A' + shift) % 26 + 'A';



	}

	std::cout << "Zaszyfrowany tekst to " << temp2;
}






void decryption(std::string str, int shift) {
	std::string temp2 = str;

	for (int i = 0; i < str.size(); i++) {


		if (is_special_character(str[i])) {
			continue;
		}

		int temp1 = (str[i] - 'A' - shift);
		if (temp1 < 0) {
			temp2[i] = temp1 + 26 + 'A';
		}
		else if (temp1 > 26) {
			temp2[i] = temp1 - 26 + 'A';
		}
		else {
			temp2[i] = temp1 + 'A';
		}


	}

	std::cout << "Odszyfrowany tekst to " << temp2;

}