#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>

using namespace std;
int N;
int i = 0;
int N1[2000000][2];
void hannoi(int n, int depart, int tmp, int dest) {
	if (n == 1) {
		N1[i][0] = depart;
		N1[i++][1] = dest;
		return;
	}
	else {
		hannoi(n - 1, depart, dest, tmp);
		N1[i][0] = depart;
		N1[i++][1] = dest;

		hannoi(n - 1, tmp, depart, dest);

	}


}

int main() {
	cin >> N;


	hannoi(N, 1, 2, 3);

	cout << i << endl;
	for (int j = 0; j < i; j++) {
		for (int i1 = 0; i1 < 2; i1++) {
			printf("%d ", N1[j][i1]);
		}
		printf("\n");
	}


}