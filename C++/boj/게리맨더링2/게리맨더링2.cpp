#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <limits.h>

using namespace std;

int N;
int A[21][21];
int result = INT_MAX;

int getValue(int starti, int endi, int startj , int endj, int check[51][51] , int index) {
	int value = 0;
	for (int i = starti; i <= endi; i++) {
		for (int j = startj; j <= endj; j++) {
			if (check[i][j] == 5) {
				continue;
			}
			check[i][j] = index;
			value += A[i][j];
		}
	}
	return value;
}

int garymandering(int x, int y, int d1, int d2) {
	int check[51][51] = { 0, };
	int value[5] = { 0, };

	for (int i = 0; i <= d1; i++) {
		check[x + i][y - i] = 5;
		check[x + d2 + i][y + d2 - i] = 5;
	}
	for (int i = 0; i <= d2; i++) {
		check[x + i][y + i] = 5;
		check[x + d1 + i][y - d1 + i] = 5;
	}


	for (int i = 1; i <= N; i++) {
		bool flag = false;
		
		int first = -1;
		int second = -1;

		for (int j = 1; j <= N; j++) {
			if (check[i][j] == 5) {
				if (first == -1)
					first = j;
				else
					second = j;
				value[4] += A[i][j];
			}
		}
		if (first != -1 && second != -1) {
			for (int j = first + 1; j < second; j++) {
				check[i][j] = 5;
				value[4] += A[i][j];
			}
		}
	}
	value[0] = getValue(1, x + d1 - 1, 1, y, check, 1);
	value[1] = getValue(1, x + d2, y + 1, N, check, 2);
	value[2] = getValue(x + d1, N, 1, y - d1 + d2 - 1, check, 3);
	value[3] = getValue(x + d2 + 1, N, y - d1 + d2, N, check, 4);

	int minvalue = INT_MAX;
	int maxvalue = 0;

	for (int i = 0; i <= 4; i++) {
		minvalue = min(minvalue,value[i]);
		maxvalue = max(maxvalue, value[i]);
	}
	return maxvalue - minvalue;
}

int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			scanf("%d", &A[i][j]);
		}
	}
	for (int r = 1; r <= N; r++) {
		for (int c = 1; c <= N; c++) {
			for (int d1 = 1; d1 <= N; d1++) {
				for (int d2 = 1; d2 <= N; d2++) {
					if ( (r + d1 + d2) <= N && c- d1 >= 1 && (c - d1) < c && (c + d2) <= N) {
						result = min(result, garymandering(r, c, d1, d2));
					
					}
				}
			}
		}
	}
	
	cout << result;
	//system("Pause");
}