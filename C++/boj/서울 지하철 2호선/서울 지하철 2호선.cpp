#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;

int N;
vector <int> graph[3001];
int check[3001];


int dfs(int start, int current, int index, int count) {
	int result = index;

	for (int next : graph[current]) {
		if (check[next] == -1) {
			continue;
		}
		if (check[next] != index) {
			check[next] = index;
			check[next] = dfs(start, next, index, count+1);
			if (check[next] == -1)
				result = check[next];
		}
		else if (count > 2 && start == next) {
			check[next] = -1;
			return -1;
		}
	}
	return result;
}

int BFS(int start) {
	queue <int> q;

	q.push(start);
	bool bfsCheck[3001] = { false, };

	bfsCheck[start] = true;

	int length = 0;

	while (q.size()) {
		int s = q.size();
		for (int qs = 0; qs < s; qs++) {
			int front = q.front();
			q.pop();

			if (check[front] == -1)
				return length;

			for (int next : graph[front]) {
				if (bfsCheck[next] == false) {
					bfsCheck[next] = true;
					q.push(next);
				}
			}

		}
		length++;

	}
	return -1;
}

int main() {
	cin >> N;

	int station1, station2;

	for (int i = 0; i < N; i++) {
		scanf("%d %d", &station1, &station2);
		graph[station1].push_back(station2);
		graph[station2].push_back(station1);

	}

	int index = 0;

	for (int i = 1; i <= N; i++) {
		if (check[i] != -1) {
			check[i] = ++index;
			if (dfs(i, i, index, 1) == -1)
				break;
		
		}



	}

	for (int i = 1; i <= N; i++) {
		if (check[i] == -1) {
			printf("0 ");
		}
		else {
			printf("%d ", BFS(i));
		}
	}

	//system("Pause");
}
