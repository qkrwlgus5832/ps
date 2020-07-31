#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;

int N, M;

int graph[51][51];
int answer[51][51];
bool check[51][51];

int dir[4][2] = { {-1,0}, {1,0}, {0,-1}, {0,1} };

void checkCommitted(vector <pair <int ,int>> &tmp, int h) {
	for (int i = 0; i < tmp.size(); i++) {
		if (check[tmp[i].first][tmp[i].second] == false) {
			check[tmp[i].first][tmp[i].second] = true;
			answer[tmp[i].first][tmp[i].second] = h - 1;
		}
	}
}

void bfs(int i, int j, bool bfscheck[51][51], int h) {
	vector <pair<int, int>> tmp;
	queue <pair <int, int>> q;
	if (bfscheck[i][j] == true) {
		return;
	}
	q.push({ i,j });
	bfscheck[i][j] = true;
	tmp.push_back({ i,j });
	bool flag = false;

	while (q.size()) {
		pair <int, int> front = q.front();
		q.pop();

		for (int i1 = 0; i1 < 4; i1++) {
			int ni = front.first + dir[i1][0];
			int nj = front.second + dir[i1][1];

			if (ni < 0 || nj < 0 || ni >= N || nj >= M) {
				flag = true;
				continue;
			}

			if (bfscheck[ni][nj] == false && graph[ni][nj] < h) {
				bfscheck[ni][nj] = true;
				tmp.push_back({ ni,nj });
				q.push({ ni,nj });
			}
		}
	}
	if (flag) {
		checkCommitted(tmp, h);
	}
	return;
}

int getAnswer() {
	int result = 0;
	for (int i = 1; i < N - 1; i++) {
		for (int j = 1; j < M - 1; j++) {
			result += (answer[i][j] - graph[i][j]);
		}
	}
	return result;
}
int main() {
	cin >> N >> M;
	int maxHeight = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%1d", &graph[i][j]);
			maxHeight = max(maxHeight, graph[i][j]);
		}

	}
	int result = 0;

	for (int h=2; h<= maxHeight + 1; h++){
		queue <pair <int, int>> q;
		bool bfscheck[51][51] = { false, };
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (graph[i][j] < h && check[i][j] == false) {
					answer[i][j]++;
					if (i!=0 && j!=0 && i!= N-1 && j!= M-1) {
						if (bfscheck[i][j] == false) {
							q.push({ i,j });
			
						}
					}
				}
			}
		}
		while (q.size()) {
			if (bfscheck[q.front().first][q.front().second] == false) {
				bfs(q.front().first, q.front().second, bfscheck, h);
			}
			q.pop();
		}
	}


	cout << getAnswer();
	//system("Pause");
}
