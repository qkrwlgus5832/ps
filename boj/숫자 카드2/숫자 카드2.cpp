#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector <int> inputs;

int N, M;

int main() {
	cin >> N;
	int input;

	for (int i = 0; i < N; i++) {
		scanf("%d", &input);
		inputs.push_back(input);
	}

	sort(inputs.begin(), inputs.end());

	cin >> M;
	for (int i = 0; i < M; i++) {
		scanf("%d", &input);
		auto iterLower = lower_bound(inputs.begin(), inputs.end(), input);
		auto iterUpper = upper_bound(inputs.begin(), inputs.end(), input);

		printf("%d ", iterUpper - iterLower);
	}
	//system("Pause");
}
