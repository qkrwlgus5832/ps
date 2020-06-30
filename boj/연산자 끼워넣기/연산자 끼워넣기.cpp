#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <limits.h>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int Number[12];
int oper[5];

int minResult = INT_MAX;
int maxResult = INT_MIN;

int calculate(vector<int> v) {
	int value = Number[0];
	for (int i = 0; i < N - 1; i++) {
		if (v[i] == 0) {
			value += Number[i + 1];
		}
		else if (v[i] == 1) {
			value -= Number[i + 1];
		}
		else if (v[i] == 2) {
			value *= Number[i + 1];
		}
		else if (v[i] == 3) {
			if (value < 0 && Number[i + 1] > 0) {
				value *= -1;
				value /= Number[i + 1];
				value *= -1;
			}
			else
				value /= Number[i + 1];
		}
	}
	return value;
}

void operInsert(vector <int> v) {
	if (v.size() == N - 1) {
		int value = calculate(v);
		minResult = min(minResult, value);
		maxResult = max(maxResult, value);
		return;
	}
	for (int i = 0; i < 4; i++) {
		if (oper[i] > 0) {
			oper[i]--;
			v.push_back(i);
			operInsert(v);
			v.pop_back();
			oper[i]++;
		}
	}
}

int main() {
	cin >> N;
	int tmp;
	for (int i = 0; i < N; i++) {
		scanf("%d", &Number[i]);
	}
	for (int i = 0; i < 4; i++) {
		scanf("%d", &oper[i]);
	}
	vector <int> v;

	operInsert(v);
	cout << maxResult << endl;
	cout << minResult;
	//system("Pause");
}