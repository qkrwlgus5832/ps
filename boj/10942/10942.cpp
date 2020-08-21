#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

int check[2001][2001];
int N;

vector <int> v;

void palindromeOdd(int i) {
	
	int length = 1;
	check[i + 1][i + 1] = 1;

	while (1) {
		if (i + length >= N || i - length < 0)
			break;

		if (v[i + length] == v[i - length]) {
			check[i - length + 1][i + length + 1] = 1;
			length++;
			
		}
		else
			break;
	}

}

void palindromeEven(int i, int j) {
	int length = 1;
	check[i + 1][j + 1] = 1;

	while (1) {
		if (j + length >= N || i - length < 0)
			break;

		if (v[j + length] == v[i - length]) {
			check[i - length + 1][j + length + 1] = 1;
			length++;
			
		}
		else
			break;
	}

}
int main() {

	cin >> N;


	v.resize(N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &v[i]);
	}

	for (int i = 0; i < N; i++) {
		palindromeOdd(i);
		if (i < N - 1 && v[i] == v[i + 1]) {
			palindromeEven(i, i + 1);
		}
	}

	int M;

	int S, E;
	cin >> M;

	for (int i = 0; i < M; i++) {
		scanf("%d %d", &S, &E);

		printf("%d\n", check[S][E]);
		
	}
	//system("Pause");
}
