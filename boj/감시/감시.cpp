#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <vector>
#include <memory.h>
#include <queue>
#include <algorithm>
#include <limits.h>

using namespace std;

int N, M;
int graph[9][9];

int dir[4][2] = { {-1,0 },{1,0},{0,-1},{0,1} };

vector <vector <string>> A;
vector <pair <int, int>> cctvs;
int cctvindex[9][9];
int result = INT_MAX;

int getdirIndex(char direction){
	if (direction == 'u') {
		return 0;
	}  
	if (direction == 'd') {
		return 1;
	}
	if (direction == 'l') {
		return 2;
	}
	if (direction == 'r') {
		return 3;
	}

}

void BFS(int i, int j, char direction, int tmpgraph[9][9]) {

	queue <pair <int, int>> q;

	q.push(make_pair(i, j));
	tmpgraph[i][j] = '#';
	while (!q.empty()) {
		pair <int, int> front = q.front();
		q.pop();
		int dirIndex = getdirIndex(direction);

		int ni = front.first + dir[dirIndex][0];
		int nj = front.second + dir[dirIndex][1];

		if (ni < 0 || nj < 0 || ni >= N || nj >= M)
			break;
		if (graph[ni][nj] == 6) {
			break;
		}
		q.push(make_pair(ni, nj));
		tmpgraph[ni][nj] = '#';
	}
	
}

void recursion(int i, vector <string> cctvorder) {
	if (i == cctvs.size()) {
		int tmpgraph[9][9];

		memcpy(tmpgraph, graph, sizeof(graph));

		for (int i1 = 0; i1 < cctvs.size(); i1++) {
			for (int j1 = 0; j1 < cctvorder[i1].size(); j1++) {
				BFS(cctvs[i1].first, cctvs[i1].second, cctvorder[i1][j1], tmpgraph);
			}
		}
		int count = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (tmpgraph[i][j] == 0)
					count++;
			}
		}
		result = min(result, count);
		return;
	}

	int rotation = graph[cctvs[i].first][cctvs[i].second] - 1;

	for (int i1 = 0; i1 < A[rotation].size(); i1++) {
		cctvorder.push_back(A[rotation][i1]);

		recursion(i + 1, cctvorder);
		cctvorder.pop_back();
	}
}

void cctvpush(int index, string tmp) {
	
	A[index].push_back(tmp);
}
int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &graph[i][j]);
			if (graph[i][j] >= 1 && graph[i][j] <=5)
				cctvs.push_back(make_pair(i, j));
		}
	}
	A.resize(5);
	cctvpush(0, "u");
	cctvpush(0, "l");
	cctvpush(0, "r");
	cctvpush(0, "d");

	cctvpush(1, "lr");
	cctvpush(1, "ud");

	cctvpush(2,  "ru");
	cctvpush(2, "lu");
	cctvpush(2, "ld");
	cctvpush(2, "rd");

	cctvpush(3, "lur");
	cctvpush(3, "uld");
	cctvpush(3, "lrd");
	cctvpush(3, "urd");

	cctvpush(4, "urld");
	vector <string> cctvorder;

	
	recursion(0, cctvorder);
	cout << result;
	
	//system("Pause");

}