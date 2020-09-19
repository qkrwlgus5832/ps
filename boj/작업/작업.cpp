#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;


int executeTime[10001];
int depth[10001];
int dp[10001];


struct job {
	int node;
	int time;
};
int N;
vector <int> graph[10001];

int topologicalSort() {
	queue <job> q;

	int time = 0;

	for (int i = 1; i <= N; i++) {
		if (depth[i] == 0) {
			q.push({ i, executeTime[i] });
			dp[i] = executeTime[i];
			time = max(time, executeTime[i]);
		}
	}
	while (q.size()) {
		job front = q.front();
		q.pop();


		bool flag = false;
		for (int next : graph[front.node]) {
			if (depth[next] >0) {
				if (--depth[next] == 0)
					q.push({ next, front.time + executeTime[next] });
				dp[next] = max(dp[next], dp[front.node] + executeTime[next]);
				time = max(time, dp[next]);
			}
		}

	}
	return time;
}

int main() {
	cin >> N;

	int time;
	int count;
	int node;

	for (int i = 0; i < N; i++) {
		scanf("%d", &time);
		executeTime[i + 1] = time;
		scanf("%d", &count);
		for (int j = 0; j < count; j++) {
			scanf("%d", &node);
			graph[node].push_back(i + 1);
		}
		depth[i + 1] = count;
	}

	cout << topologicalSort();
	//system("Pause");
}
