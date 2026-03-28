#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

int N;

vector <int> graph[10001];
int childCount[10001][2];
int col[10001];
int depth[10001];

void dfs(int node) {
	int leftChild = graph[node][0];
	int rightChild = graph[node][1];

	int leftCount = 0;
	int rightCount = 0;

	if (leftChild != -1) {
		dfs(leftChild);
		leftCount += childCount[leftChild][0] + childCount[leftChild][1] + 1;

	}
	if (rightChild != -1) {
		dfs(rightChild);
		rightCount += childCount[rightChild][0] + childCount[rightChild][1] + 1;
	}
	childCount[node][0] = leftCount;
	childCount[node][1] = rightCount;
}

void getCol(int node) {
	int leftNode = graph[node][0];
	int rightNode = graph[node][1];

	if (leftNode != -1) {
		col[leftNode] = col[node] - (childCount[leftNode][1] + 1);
		getCol(leftNode);
	}
	if (rightNode != -1) {
		col[rightNode] = col[node] + childCount[rightNode][0] + 1;
		getCol(rightNode);
	}
}

pair <int ,int> BFS(int root) {
	queue <int> q;

	int level = 1;
	int resultLevel = 0;
	int resultLength = 0;

	q.push(root);

	while (q.size()) {
		int s = q.size();
		int minCol = INT_MAX;
		int maxCol = 0;

		for (int qs = 0; qs < s; qs++) {
			int front = q.front();
			q.pop();

			for (int i = 0; i < graph[front].size(); i++) {
				if (graph[front][i] != -1) {
					q.push(graph[front][i]);
					
				}
			}
			minCol = min(minCol, col[front]);
			maxCol = max(maxCol, col[front]);
		}
		
		if (resultLength < maxCol - minCol + 1) {
			resultLength = maxCol - minCol + 1;
			resultLevel = level;
		}
		level++;
		
	}
	return { resultLevel, resultLength };
}
int main() {
	cin >> N;

	int node;
	int left;
	int right;

	for (int i = 0; i < N; i++) {
		scanf("%d", &node);
		scanf("%d", &left);
		scanf("%d", &right);

		depth[left]++; depth[right]++;
		graph[node].push_back(left);
		graph[node].push_back(right);
	}

	int root = 1;

	for (int i = 1; i <= N; i++) {
		if (depth[i] == 0) {
			root = i;
			break;
		}
	}
	dfs(root);

	col[root] = childCount[root][0] + 1;
	getCol(root);
	pair <int, int> result = BFS(root);
	cout << result.first << " " << result.second;

	//system("Pause");
}
