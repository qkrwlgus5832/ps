#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N;

vector <int> graph[1000001];
bool dfsCheck[1000001];
vector <int> level[1000001];
int maxDepth = 1;
vector <int> tree[1000001];


void DFS(int x, int depth) {

	maxDepth = max(maxDepth, depth);


	for (auto tmp : graph[x]) {
		if (dfsCheck[tmp] == false) {
			dfsCheck[tmp] = true;
			level[depth + 1].push_back(tmp);
			tree[x].push_back(tmp);
			DFS(tmp, depth + 1);
		}
		
	}

}

bool earlyAdapter[1000001];

int getAnswer() {
	int result = 0;
	for (int i = maxDepth - 1; i >= 1; i--) {
		for (int j = 0; j < level[i].size(); j++) {
			int nodeNumber = level[i][j];

			bool flag = true;

			for (int child : tree[nodeNumber]) {
				if (earlyAdapter[child] == false) {
					flag = false;
				}
			}
			if (flag == false) {
				earlyAdapter[nodeNumber] = true;
				result++;
			}
		}
	}
	return result;
}
int main() {
	cin >> N;

	int u, v;

	for (int i = 0; i < N - 1; i++) {
		scanf("%d %d", &u, &v);
		graph[u].push_back(v);
		graph[v].push_back(u);

	}
	level[1].push_back(1);
	dfsCheck[1] = true;
	DFS(1, 1);
	cout << getAnswer();

	//system("Pause");
}