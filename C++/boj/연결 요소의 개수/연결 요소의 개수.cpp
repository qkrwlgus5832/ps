#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

vector <int> graph[1001];
bool check[1001];

void BFS(int x) {
	queue <int> q;

	q.push(x);
	check[x] = true;

	while (q.size()) {
		int front = q.front();
		q.pop();

		
		for (int next : graph[front]) {
			if (check[next] == false) {
				check[next] = true;
				q.push(next);
			}
		}
	}
}
int main() {
	int N, M;
	cin >> N >> M;

	int u, v;

	for (int i = 0; i < M; i++) {
		scanf("%d %d", &u, &v);
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	int count = 0;
	for (int i = 1; i <= N; i++) {
		if (check[i] == false) {
			BFS(i);
			count++;
		}
	}
	cout << count;
	//system("Pause");
}

