#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <math.h>
#include <algorithm>
#include <map>
using namespace std;

int graph[2200][2200];

map <int, int> result;

void divideAndConquer(int size, int i, int j) {
	bool flag = false;
	for (int i1 = i; i1 < i + size; i1++) {
		for (int j1 = j; j1 < j + size; j1++) {
			if (graph[i][j] != graph[i1][j1]) {
				flag = true;
				break;
			}
		}
	}
	if (flag) {
		for (int i1 = i; i1 < i + size; i1 += size / 3) {
			for (int j1 = j; j1 < j + size; j1 += size / 3) {
				divideAndConquer(size / 3, i1, j1);
			}
		}
		return;
	}

	result[graph[i][j]]++;

}
int main() {
	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &graph[i][j]);
		}
	}
	divideAndConquer(N, 0, 0);
	cout << result[-1] << endl;
	cout << result[0] << endl;
	cout << result[1] << endl;
	//system("Pause");
}
