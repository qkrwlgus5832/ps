#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int changeLocation[101];

int BFS(int x) {
	bool check[101] = { false, };
	queue <int> q;
	q.push(x);
	check[x] = true;
	int length = 0;
	while (q.size()) {
		int s = q.size();
		for (int qs = 0; qs < s; qs++) {
			int front = q.front();
			q.pop();
			if (front == 100) {
				return length;
			}
			else {
				for (int i = 1; i <= 6; i++) {
					if (front + i <= 100 && check[front + i] == false) {
						check[front + i] = true;
						if (changeLocation[front + i] > 0) {
							check[changeLocation[front + i]] = true;
							q.push(changeLocation[front + i]);
						}
						else {
							q.push(front + i);
						}

					}
				}
			}
		}
		length++;
	}
}
int main() {
	int N, M;

	cin >> N >> M;
	int x, y;
	int u, v;
	for (int i = 0; i < N; i++) {
		scanf("%d %d", &x, &y);
		changeLocation[x] = y;
	}
	for (int i = 0; i < M; i++) {
		scanf("%d %d", &u, &v);
		changeLocation[u] = v;
	}
	cout << BFS(1);
//	system("Pause");
}
