#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;

vector <int> graph[10001];
int dp[10001][2];
int check[10001];


void dfs(int x) {
	
	int sum1 = 0;
	int sum2 = 0;

	for (int i = 0; i < graph[x].size(); i++) {
		if (check[graph[x][i]] == false) {
			check[graph[x][i]] = true;
			dfs(graph[x][i]);
			sum1 += dp[graph[x][i]][0];
			sum2 += max(dp[graph[x][i]][0], dp[graph[x][i]][1]);
		}

	}
	 
	dp[x][0] = sum2;
	dp[x][1] = dp[x][1] + sum1;
}

int main() {
	int N;

	cin >> N;

	int people;

	for (int i = 0; i < N; i++) {
		scanf("%d", &dp[i + 1][1]);
	}

	int node1, node2;
	
	for (int i = 0; i < N - 1; i++) {
		scanf("%d %d", &node1, &node2);
		graph[node1].push_back(node2);
		graph[node2].push_back(node1);
	}


	check[1] = true;


	dfs(1);

	cout << max(dp[1][0], dp[1][1]);
	//system("Pause");
}
