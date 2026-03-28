#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;


int main() {
	string input;
	cin >> input;

	int numberSize = 10;
	int charSize = 26;

	int result = 1;

	for (char ch : input) {
		if (ch == 'd') {
			charSize = 26;
			result *= numberSize;
			if (numberSize == 10) numberSize--;

		
		}
		else if (ch == 'c') {
			numberSize = 10;
			result *= charSize;
			if (charSize == 26) charSize--;
		}
	}
	cout << result;
	//system("Pause");
}
