#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector <int> B;

int result = INT_MAX;


void getCount(int x, int count) {
	if ()

}


int getAnswer(int x) {
	for (int i = -1; i <= 1; i++) {
		vector <int> A(B);
		getCount(x, abs(i));
	}

	return 0;
}
int main() {
	int N;
	cin >> N;

	B.resize(N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &B[i]);
	}

	if (N == 1) {
		cout << 0;
		return 0;
	}

	int minDiff = INT_MAX;
	int maxDiff = 0;

	for (int i = 1; i < N; i++) {
		int diff = B[i] - B[i - 1];
		minDiff = min(diff, minDiff);
		maxDiff = max(diff, maxDiff);
	}

	if (maxDiff - minDiff > 4) {
		cout << -1;
		return 0;
	}


	system("Pause");
}
