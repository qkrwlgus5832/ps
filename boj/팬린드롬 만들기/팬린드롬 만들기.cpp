#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;


int inputCount[27];

int main() {
	string input;
	cin >> input;


	for (auto ch : input) {
		inputCount[ch - 'A']++;
	}

	int index = -1;
	for (int i = 0; i <= 'Z' - 'A'; i++) {
		if (inputCount[i] % 2 != 0) {
			if (index == -1) {
				inputCount[i]--;
				index = i;
			}
			else {
				cout << "I'm Sorry Hansoo";
				return 0;
			}
		}
	}

	string result = "";

	for (int i = 0; i <= 'Z' - 'A'; i++) {
		if (inputCount[i] % 2 == 0) {
			for (int j = 0; j < inputCount[i] / 2; j++) {
				result += ('A' + i);
			}
		}
	}
	if (index != -1) {
		result += ('A' + index);
	}

	for (int i = 'Z' - 'A'; i >= 0; i--) {
		if (inputCount[i] % 2 == 0) {
			for (int j = 0; j < inputCount[i] / 2; j++) {
				result += ('A' + i);
			}
		}
	}

	cout << result;
	//system("Pause");
}
