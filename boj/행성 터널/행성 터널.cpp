#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;


struct edge {
	int start;
	int end;
	int distance;
};

vector <pair <int, int>> v[3];
vector <edge> edges;

int unionFind[100001];
int N;

int find(int x){
	if (unionFind[x] == -1) {
		return x;
	}
	
	int parent = find(unionFind[x]);
	unionFind[x] = parent;
	return parent;
}

void merge(int a, int b) {
	unionFind[a] = b;
}

long long spanningTree() {
	int count = 0;

	long long result = 0;

	for (edge edge_ : edges) {
		if (count == N - 1) {
			break;
		}
		int parentStart = find(edge_.start);
		int parentEnd = find(edge_.end);

		if (parentStart != parentEnd) {
			merge(parentStart, parentEnd);
			count++;
			result += edge_.distance;
		}
	}
	return result;
}
int main() {

	cin >> N;

	int x, y, z;

	for (int i = 0; i < N; i++) {
		scanf("%d %d %d", &x, &y, &z);
		v[0].push_back({ x, i });
		v[1].push_back({ y,i });
		v[2].push_back({ z,i });
	}

	for (int i = 0; i < 3; i++) {
		sort(v[i].begin(), v[i].end());
	}

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < v[i].size() - 1; j++) {
			edges.push_back({ v[i][j].second, v[i][j + 1].second, v[i][j + 1].first - v[i][j].first });
		}
	}
	sort(edges.begin(), edges.end(), [](const edge& a, const edge& b) {
		return a.distance < b.distance;
	});

	memset(unionFind, -1, sizeof(unionFind));

	cout << spanningTree();
	//system("Pause");
}
