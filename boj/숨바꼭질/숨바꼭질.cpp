#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

int N, M;
vector <int> graph[20001];
bool check[20001];
vector <int> level[20001];

int maxLength = 1;

void BFS() {
	queue <int> q;
	q.push(1);
	check[1] = true;

	int length = 1;

	while (q.size()) {
		int s = q.size();
		
		for (int qs = 0; qs < s; qs++) {
			int front = q.front();
			q.pop();

			for (int next : graph[front]) {
				if (check[next] == false) {
					check[next] = true;
					level[length].push_back(next);
					q.push(next);
				}
			}
		}
		maxLength = max(maxLength, length);
		length++;
	}
}
int main() {
	cin >> N >> M;

	int A_i, B_i;

	for (int i = 0; i < M; i++) {
		scanf("%d %d", &A_i, &B_i);
		graph[A_i].push_back(B_i);
		graph[B_i].push_back(A_i);
	}

	BFS();
	
	sort(level[maxLength - 1].begin(), level[maxLength - 1].end());

	cout << level[maxLength - 1][0] << " " << maxLength - 1 << " " << level[maxLength - 1].size();
	//system("Pause");
}
