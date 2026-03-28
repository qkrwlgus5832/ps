#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <string>
#include <queue>
#include <memory.h>
using namespace std;


int N, M;

char graph[102][102];
int dir[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };

pair <bool, int> BFS(int i, int j, bool keycheck[27]) {
	bool flag = false;
	int document = 0;

	queue <pair <int, int>> q;
	bool check[102][102] = { false, };

	q.push(make_pair(i, j));
	check[i][j] = true;

	while (q.size()) {
		pair <int, int> front = q.front();
		q.pop();

		for (int i1 = 0; i1 < 4; i1++) {
			int ni = front.first + dir[i1][0];
			int nj = front.second + dir[i1][1];

			if (ni < 0 || nj < 0 || ni > N + 1 || nj > M + 1 || graph[ni][nj] == '*' || check[ni][nj]== true)
				continue;

			check[ni][nj] = true;

			if (graph[ni][nj] >= 'a' && graph[ni][nj] <= 'z') {
				if (keycheck[graph[ni][nj] - 'a'] == false) {
					keycheck[graph[ni][nj] - 'a'] = true;
					flag = true;
				}
				graph[ni][nj] = '.';
			
			}
			else if (graph[ni][nj] >= 'A' && graph[ni][nj] <= 'Z') {
				if (keycheck[graph[ni][nj] - 'A'] == true) {
					graph[ni][nj] = '.';
					flag = true;

					q.push(make_pair(ni, nj));

				}
				continue;
			}
			else if (graph[ni][nj] == '$') {
				graph[ni][nj] = '.';
				document++;
				flag = true;
			}
			q.push(make_pair(ni, nj));
		}

	}
	return make_pair(flag, document);
}
int main() {
	int T;
	cin >> T;

	for (int t = 1; t <= T; t++) {
		memset(graph, 0, sizeof(graph));
		scanf("%d %d", &N, &M);
		for (int i = 1; i <= N; i++) {
			string input;
			cin >> input;
			for (int j = 1; j <= M; j++) {
				graph[i][j] = input[j - 1];
			}
		}
		bool keycheck[27] = { false, };

		string keys;
		cin >> keys;

		for (int i = 0; i < keys.size(); i++) {
			keycheck[keys[i] - 'a'] = true;
		}

		int result = 0;
		while (1) {
			pair <bool, int> tmp = BFS(0, 0,keycheck);
			if (tmp.first == false) {
				break;
			}
			else {
				result += tmp.second;
			}
		}
		
		printf("%d\n", result);

	}
	//system("Pause");

}
