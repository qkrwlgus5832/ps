#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
using namespace std;

string input;

int check[51];
vector <int> v;

void recursion(string input, int index, int count) {
	if (index == input.size()) {
		for (int i = 1; i <= count; i++) {
			if (check[i] == false) {
				return;
			}
		}
		for (int tmp : v) {
			printf("%d ", tmp);
		}
		exit(0);
	}

	if (check[input[index] - '0'] == 0) {
		check[input[index] - '0']++;
		v.push_back(input[index] - '0');
		recursion(input, index + 1, count + 1);
		check[input[index] - '0']--;
		v.pop_back();
	}
	if (input[index] <= '5' && index + 1< input.size()) {
		int currentNumber = input[index] - '0';
		int nextNumber = input[index + 1] - '0';
		if (check[currentNumber * 10 + nextNumber] == 0) {
			check[currentNumber * 10 + nextNumber] = 1;
			v.push_back(currentNumber * 10 + nextNumber);
			recursion(input, index + 2, count + 1);
			check[currentNumber * 10 + nextNumber] = 0;
			v.pop_back();
		}

	}

}

int main() {
	cin >> input;

	recursion(input, 0, 0);

	//system("Pause");
}
