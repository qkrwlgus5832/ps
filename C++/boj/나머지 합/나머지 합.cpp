#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;


vector <long long> v;
long long check[1001];

int main() {

	int N, M;

	cin >> N >> M;


	v.resize(N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &v[i]);
	}

	for (int i = 1; i < N; i++) {
		v[i] = v[i - 1] + v[i];
	}

	long long result = 0;

	for (int i = 0; i < N; i++) {
		if (v[i] % M  == 0) {
			result++;
		}

		check[v[i] % M]++;
		
	}

	for (int i = 0; i < M; i++) {
		if (check[i] >= 2) {
			result += (check[i] * (check[i] - 1)) / 2;
		}
	}
	cout << result;
	//system("Pause");
}
