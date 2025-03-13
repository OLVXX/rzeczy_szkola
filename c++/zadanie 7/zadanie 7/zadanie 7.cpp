#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // Open the input file
    ifstream input_file("H:\programowanie\przedmioty_szkola\c++\zadanie 7\instrukcje.txt");

    // Check if the file was opened successfully
    if (!input_file) {
        cerr << "Error: could not open input file." << endl;
        return 1;
    }

    // Initialize variables for the different tasks
    int total_length = 0;
    string longest_sequence_type;
    int longest_sequence_length = 0;
    char most_frequent_char = '\0';
    int most_frequent_char_count = 0;
    string result;

    // Read the instructions from the file
    vector<pair<string, string>> instructions;
    string line;
    while (getline(input_file, line)) {
        // Split the line into two parts: the instruction type and the instruction argument
        size_t separator_pos = line.find(' ');
        string type = line.substr(0, separator_pos);
        string arg = line.substr(separator_pos + 1);

        // Update the variables for task 1
        if (type == "DOPISZ") {
            total_length += arg.length();
        }
        else if (type == "USUN") {
            total_length -= stoi(arg);
        }

        // Update the variables for task 2
        static int current_sequence_length = 0;
        static string current_sequence_type;
        if (type == current_sequence_type) {
            current_sequence_length++;
            if (current_sequence_length > longest_sequence_length) {
                longest_sequence_length = current_sequence_length;
                longest_sequence_type = type;
            }
        }
        else {
            current_sequence_length = 1;
            current_sequence_type = type;
        }

        // Update the variables for task 3
        if (type == "DOPISZ") {
            for (char c : arg) {
                int count = count_if(arg.begin(), arg.end(), [c](char x) {return x == c; });
                if (count > most_frequent_char_count) {
                    most_frequent_char_count = count;
                    most_frequent_char = c;
                }
            }
        }

        // Update the result for task 4
        if (type == "DOPISZ") {
            result += arg;
        }
        else if (type == "USUN") {
            result.erase(result.end() - stoi(arg), result.end());
        }
    }

    // Write the results to the output file
    ofstream output_file("wyniki.txt");
    output_file << "Podpunkt 1: " << total_length << endl;
    output_file << "Podpunkt 2: rodzaj instrukcji - " << longest_sequence_type << ", dlugosc ciagu - " << longest_sequence_length << endl;
    output_file << "Podpunkt 3: litera - " << most_frequent_char << ", ilosc - " << most_frequent_char_count << endl;
    output_file << "Podpunkt 4: " << result << endl;

    // Close the input and output files
    input_file.close();
    output_file.close();

    return 0;
}
