#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;


vector <char> alpha;
int check[11];
int alphaValue['Z' + 1];
int result = 0;
vector <string> inputs;
map <char, int> m;

int getValue() {
	int sum = 0;
	
	for (string input : inputs) {
		int tmpsum = 0;
		for (char tmp : input) {
			tmpsum = tmpsum * 10 + alphaValue[tmp];
		}
		sum += tmpsum;
	}
	return sum;
}
void recursion(int index) {
	if (index == alpha.size()) {
		result = max(result, getValue());
		return;
	}

	for (int value = 0; value <= 9; value++) {
		if (check[value] == false) {
			alphaValue[alpha[index]] = value;
			check[value] = true;
			recursion(index + 1);
			alphaValue[alpha[index]] = 0;
			check[value] = false;
		}
	}

}




int main() {
	int N;
	cin >> N;
	string input;

	for (int i = 0; i < N; i++) {
		cin >> input;

		for (int j = 0; j < input.size(); j++) {
			if (m[input[j]] == 0) {
				m[input[j]] = 1;
				alpha.push_back(input[j]);
			}
		}
	
		inputs.push_back(input);

	}

	recursion(0);

	cout << result;
	//system("Pause");
}
