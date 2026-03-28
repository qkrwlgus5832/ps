#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <queue>
#include <set>
#include <limits.h>

using namespace std;

int N, M, K;

vector <pair <int,int>> graph[10001];
int check[10001];

long long result = LLONG_MAX;
void dfs(int current, multiset <int>& s, long long sum) {
	if (current == N) {
		int tmpM = K;
		for (auto iter = s.rbegin(); iter != s.rend() && tmpM >0; iter++, tmpM--) {
			sum -= *iter;
		}
		result = min(result, sum);
	}
	for (auto node : graph[current]) {
		if (check[node.first] == 0) {
			check[node.first] = 1;
			s.insert(node.second);
			dfs(node.first, s, sum + node.second);
			s.erase(node.second);
			check[node.first] = 0;
		}
	}
}

int main() {

	cin >> N >> M >> K;

	int start, end, time;

	for (int i = 0; i < N; i++) {
		scanf("%d %d %d", &start, &end, &time);
		graph[start].push_back({ end, time });
	}

	multiset <int> s;
	dfs(1, s, 0);

	cout << result;
	//system("Pause");
}