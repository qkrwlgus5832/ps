#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector <int> input;
int N, L, R, X;
long long result = 0;

bool isAnswer(vector <int> & v) {
	int minValue = v[0];
	int maxValue = v[0];
	
	int sum = v[0];
	for (int i = 1; i < v.size(); i++) {
		minValue = min(minValue, v[i]);
		maxValue = max(maxValue, v[i]);
		sum += v[i];
	}

	return (sum >= L) && (sum <=R) && (maxValue - minValue >= X);

}


void combination(int index, vector <int>& v) {
	if (v.size() >= 2) {
		result += isAnswer(v);
	}
	for (int i = index; i < N; i++) {
		v.push_back(input[i]);
		combination(i + 1, v);
		v.pop_back();
	}
}
int main() {

	cin >> N >> L >> R >> X;

	input.resize(N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &input[i]);
	}

	vector <int> v;
	combination(0, v);
	cout << result;

	//system("Pause");
}

