#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int N;

string input;


vector <int> number;
vector <char> operator_;
bool check[21];

int result = -1;
int f = 0;

int tmpoperation(int number1, int _operator, int number2) {
	if (_operator == '+') {
		return number1 + number2;
	}
	else if (_operator == '-') {
		return number1 - number2;
	}
	else if (_operator == '*') {
		return number1 * number2;
	}
}



int operation() {
	int value = 0;

	if (check[0] == true) {
		value += tmpoperation(number[0], operator_[0], number[1]);
	}
	else {
		value += number[0];
	}

	for (int i = 0; i < operator_.size(); i++) {
		/*	if (i == 0) {

			}
			else {*/
		if (check[i] == true) {
			continue;
		}
		else {
			int tmpvalue = 0;
			if (i + 1 < operator_.size() && check[i + 1] == true) {
				tmpvalue = tmpoperation(number[i + 1], operator_[i + 1], number[i + 2]);
			}
			else {
				tmpvalue = number[i + 1];
			}

			if (operator_[i] == '+') {
				value += tmpvalue;
			}
			else if (operator_[i] == '-') {
				value -= tmpvalue;
			}
			else if (operator_[i] == '*') {
				value *= tmpvalue;
			}
		}
	}

	/*}*/
	return value;
}


void recursion(int i) {
	if (f == 0) {
		result = operation();
		f = 1;

	}
	else {
		result = max(result, operation());
	}

	for (int i1 = i; i1 < operator_.size(); i1++) {
		check[i1] = true;
		recursion(i1 + 2);
		check[i1] = false;
	}

}
int main() {
	cin >> N;
	cin >> input;

	for (int i = 0; i < N; i++) {
		if (input[i] - '0' >= 0 && input[i] - '0' <= 9) {
			number.push_back(input[i] - '0');
		}
		else {
			operator_.push_back(input[i]);
		}
	}
	recursion(0);

	cout << result;
	//system("Pause");
}