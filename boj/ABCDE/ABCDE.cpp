#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

vector <int> graph[2001];

bool dfs(int x, int level, bool check[2001]) {
	if (level == 4) {
		return true;
	}
	bool flag = false;
	for (int next : graph[x]) {
		if (check[next] == false) {
			check[next] = true;
			flag = flag || dfs(next, level + 1, check);
			check[next] = false;
		}
	}
	return flag;
}

int main() {
	int N, M;
	cin >> N >> M;

	int a, b;

	for (int i = 0; i < M; i++) {
		scanf("%d %d", &a, &b);
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	bool check[2001] = { false, };
	for (int i = 0; i < N; i++) {
		check[i] = true;
		if (dfs(i, 0, check)) {
			cout << 1;
			return 0;
		}
		check[i] = false;
	
	}
	cout << 0;
	//system("Pause");
}
