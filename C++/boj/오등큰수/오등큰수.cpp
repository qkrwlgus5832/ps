#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

stack <int> s;
vector <int> input;

int F[1000001];

int stackPop(int current) {
	while (s.size()) {
		if (F[s.top()] <= F[current]) {
			s.pop();
		}
		else
			return s.top();
	}
	if (s.size() == 0)
		return -1;
}

int main() {
	int N;
	cin >> N;

	int tmp;
	for (int i = 0; i < N; i++) {
		scanf("%d", &tmp);
		input.push_back(tmp);
	}

	for (int i = 0; i < N; i++) {
		F[input[i]]++;
	}

	vector <int> result;
	result.resize(N);

	for (int i = input.size() - 1; i >= 0; i--) {
		result[i] = stackPop(input[i]);
		s.push(input[i]);
	}

	for (int i = 0; i < N; i++) {
		printf("%d ", result[i]);
	}
	//system("Pause");
}
