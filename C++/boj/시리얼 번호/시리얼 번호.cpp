#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

vector <string> input;

int calculate(const string &tmp) {
	int sum = 0;
	for (int i = 0; i < tmp.size(); i++) {
		if (tmp[i] >= '0' && tmp[i] <= '9')
			sum += tmp[i] - '0';

	}
	return sum;
}

bool compare(string &a, string &b) {
	if (a.size() == b.size()) {
		int sumA = calculate(a);
		int sumB = calculate(b);

		if (sumA < sumB)
			return true;
		else if (sumA > sumB)
			return false;
		return a < b;
	}
	return a.size() < b.size();
}

int main() {

	int N;
	string tmp;

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> tmp;
		input.push_back(tmp);
	}

	sort(input.begin(), input.end(), compare);

	for (string tmp : input) {
		cout << tmp << endl;
	}

	//system("Pause");
}
