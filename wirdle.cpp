//#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

bool wirdle [5];

string chooseAnswer() {

	string fileInput;

	ifstream answerFile("answers.txt");
	
	vector<string> lines;

	for(string line; getline(answerFile, fileInput);) {

		line = fileInput.c_str();
		lines.push_back(line);

	}
	
	answerFile.close();

	return lines[rand() % lines.size()];

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

	for (int i = 0; i < 5; i++) {

		if (wirdle[i]) {
			cout << answer.at(i);
		} else {
			cout << '_';
		}
	}
	
	cout << '\n';
}

int main () {

	bool won = false;

	string answer = chooseAnswer();
	//cout << "The answer is: " << answer << '\n';

	cout << "_____\n";

	string userInput;
	
	for(int turns = 6; turns > 0 && !won; turns--) {

		cout << "Turns Left: " << turns << '\n';

		fill_n(wirdle, 5, false);

		cout << "Enter your answer: \n";

		cin >> userInput;

		transform(userInput.begin(), userInput.end(), userInput.begin(), ::toupper); // make uppercase

		lettersPresent(answer, userInput);

		if (answer == userInput){
			cout << "Right answer!";
			won = true;
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