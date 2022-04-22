//#include <stdio.h>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool wirdle [5];

bool compareString(string one, string two) {

	if (one == two) 
		return true;

	return false;
}

int lettersPresent(string answer, string input) {

	int lettersPresent = 0;

	for (int i = 0; i < input.size(); i++) {

		if (answer.find(input.at(i)) != string::npos) {
			lettersPresent++;
			if (answer.find(input.at(i)) == i){
				wirdle[i] = true;
			}
			
		}
	}

	return lettersPresent;

}

void printWirdle (string answer) {

	for (size_t i = 0; i < 5; i++) {

		if (wirdle[i]) {
			cout << answer.at(i);
		} else {
			cout << '_';
		}
	}
	
	cout << '\n';
}

int main () {

	bool end = false;

	string answer = "REACT";
	//cout << "The answer is: " << answer << '\n';

	cout << "_____\n";

	string userInput;
	
	for(int turns = 6; turns > 0 && !end; turns--) {

		cout << "Turns Left: " << turns << '\n';

		fill_n(wirdle, 5, false);

		cout << "Enter your answer: \n";

		cin >> userInput;

		transform(userInput.begin(), userInput.end(), userInput.begin(), ::toupper); // make uppercase

		lettersPresent(answer, userInput);

		if (answer == userInput){
			cout << "Right answer!";
			end = true;
		} else {
			cout << "Wrong answer! \n";
			cout << "Letters correct: " << lettersPresent(answer, userInput) << '\n';
			printWirdle(answer);
		}

		if (turns <= 1) {
			cout << "Out of time!" << '\n';
		}

	}

	return 0;

}