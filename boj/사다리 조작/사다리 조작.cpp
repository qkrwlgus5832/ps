#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

int N, M, H;

int check[31][11];
int result = -1;

bool simulation() {
	for (int i = 0; i < N; i++) {
		int current = i;

		for (int j = 0; j < H; j++) {
	
			if (check[j][current] > 0 ) {
				current++;
			}
			else if (current > 0 && check[j][current-1]> 0) {
				current--;
			}
			
		}
		if (current != i) {
			return false;
		}
		
	}
	return true;
}


void recursion(int index, int count) {
	if (simulation()) {
		if (result == -1) {
			result = count;
		}
		else {
			result = min(result, count);
		}
	}
	if (count == 3) {
		return;
	}
	for (int i = index; i < (N-1)* H; i++) {
		int ni = i / (N - 1);
		int nj = i % (N - 1);
		if (nj >= 1 && check[ni][nj - 1] > 0 ) {
			continue;
		}
		if (nj < N - 2 && check[ni][nj + 1] > 0) {
			continue;
		}
		if (check[ni][nj] == 2) {
			continue;
		}
		check[ni][nj] = 1;
		recursion(i + 1, count + 1);
		check[ni][nj] = 0;

	}
}



int main() {
	cin >> N >> M >> H;
	int a, b;

	for (int i = 0; i < M; i++) {
		scanf("%d %d", &a, &b);
		--a; --b;
		check[a][b] = 2;

	}
	recursion(0, 0);
	cout << result;
	//system("Pause");
}