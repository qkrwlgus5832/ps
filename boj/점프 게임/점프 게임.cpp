#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;

int graph[100001][2];
bool check[100001][2];

bool BFS(int N, int k) {
	queue <pair <int, int>> q;

	q.push({ 0,0 });
	check[0][0] = true;
	graph[0][0] = 0;

	int time = 0;

	while (q.size()) {
		int s = q.size();
		
		for (int qs = 0; qs < s; qs++) {
			pair <int, int> front = q.front();
			q.pop();

			if (front.first > N - 1)
				return true;

			if (front.first + 1 <= N - 1 && graph[front.first + 1][front.second] == 1) {
				graph[front.first + 1][front.second] = 0;
				q.push({ front.first + 1, front.second });
			}
			if (front.first - 1 > time && graph[front.first - 1][front.second] == 1) {
				graph[front.first - 1][front.second] = 0;
				q.push({ front.first - 1, front.second });
			}

			if (front.first + k > N - 1) {
				q.push({ front.first + k, !front.second });
			}
			else if (front.first + k <= N - 1 && graph[front.first + k][!front.second] == 1) {
				graph[front.first + k][!front.second] = 0;
				q.push({ front.first + k , !front.second });
			}
		}
		time++;
	}

	return false;

}

int main() {
	int N, k;
	cin >> N >> k;

	for (int j = 0; j < 2; j++) {
		for (int i = 0; i < N; i++) {
			scanf("%1d", &graph[i][j]);
		}
	}

	cout << BFS(N, k);
	//system("Pause");
}
