#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>

using namespace std;

vector <int> B;


int main() {
	int N;
	
	B.resize(N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &B[i]);
	}

	for (int i = 1; i < N; i++) {
		int diff = B[i] - B[i - 1];

		if (diff > 4) {
			cout << -1;
			return 0;
		}

	}

	system("Pause");
}
