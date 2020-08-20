#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

char graph[51][51];
int dir[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };
int N, M;

struct edge {
	pair <int,int> start;
	pair <int,int> end;
	int distance;
};
vector <edge> edges;

pair <int, int> unionFind[51][51];
bool check[51][51][51][51];


void merge(pair <int ,int>& a, pair <int ,int>& b) {

	unionFind[a.first][a.second] = b;

}

pair <int, int> find(pair <int, int>& x) {
	if (unionFind[x.first][x.second].first == -1)
		return x;
	return find(unionFind[x.first][x.second]);

}
void BFS(int i, int j) {
	bool bfscheck[51][51] = { false, };
	bfscheck[i][j] = true;

	queue <pair <int, int>> q;
	q.push({ i,j });

	int length = 0;

	while (q.size()) {
		int s = q.size();
		for (int qs = 0; qs < s; qs++) {
			pair <int, int> front = q.front();
			q.pop();

			for (int i1 = 0; i1 < 4; i1++) {
				int ni = front.first + dir[i1][0];
				int nj = front.second + dir[i1][1];

				if (ni < 0 || nj < 0 || ni >= N || nj >= N)
					continue;

				if (bfscheck[ni][nj] == false && graph[ni][nj] != '1') {
					bfscheck[ni][nj] = true;
					q.push({ ni,nj });

					if (graph[ni][nj] == 'S' || graph[ni][nj] == 'K') {
 						if (check[i][j][ni][nj] == false) {
							check[i][j][ni][nj] = true; check[ni][nj][i][j] = true;
							edges.push_back({ { i, j }, { ni,nj }, length + 1 });
						
						}
					}
				}
			}
		}
		length++;
	}

}

int spanningTree() {
	int count = 0;
	int result = 0;

	for (auto edge : edges) {
		pair <int, int> parent1 = find(edge.start);
		pair <int, int> parent2 = find(edge.end);

		if (parent1 != parent2) {
			merge(parent1, parent2);
			count++;
			result += edge.distance;
		}
		if (count == M) {
			return result;
		}
	}
	return - 1;
}
int main() {

	cin >> N >> M;

	pair <int, int> start;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> graph[i][j];
		}
	}

	memset(unionFind, -1, sizeof(unionFind));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (graph[i][j] == 'S' || graph[i][j] == 'K') {
				BFS(i, j);
			}
		}
	}
	
	sort(edges.begin(), edges.end(), [](const edge& a, const edge& b) {
		return a.distance < b.distance;
	});

	cout << spanningTree();

	//system("Pause");
}
