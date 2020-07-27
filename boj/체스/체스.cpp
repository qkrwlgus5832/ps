#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
using namespace std;


bool chess[1001][1001];

int main() {
	int n, m;
	cin >> n >> m;

	int q;
	cin >> q;

	int x, y;
	for (int i = 0; i < q; i++) {
		scanf("%d %d", &x, &y);
		chess[x][y] = true;

	}
	system("Pause");
}
