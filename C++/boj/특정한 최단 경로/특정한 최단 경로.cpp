#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
#include <memory.h>
#include <algorithm>

using namespace std;

int graph[801][801];
int unionFind[5];

int N, E;

void floid() {
	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (i == j)
					continue;

				if (graph[i][k] != INT_MAX && graph[k][j] != INT_MAX)
					graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
			}
		}
	}
}

int getLength(vector <int>& v) {
	int length = 0;
	for (int i = 0; i < v.size() - 1; i++) {
		if (graph[v[i]][v[i + 1]] == INT_MAX) {
			return -1;
		}
		
		length += graph[v[i]][v[i + 1]];

	}
	return length;
}

int getAnswer(vector <int> v1, vector <int> v2) {
	int length1 = getLength(v1);
	int length2 = getLength(v2);

	if (length1 == -1 && length2 == -1)
		return -1;
	else if (length1 == -1)
		return length2;
	else if (length2 == -1)
		return length1;
	return min(length1, length2);
	
}
int main() {

	cin >> N >> E;


	int a, b, c;

	vector <int> v;
	

	for (int i = 0; i < E; i++) {
		scanf("%d %d %d", &a, &b, &c);
		graph[a][b] = c;
		graph[b][a] = c;
	}


	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (graph[i][j] == 0)
				graph[i][j] = INT_MAX;
		}
		graph[i][i] = 0;
	}


	floid();

	int v1, v2;
	cin >> v1 >> v2;


	cout << getAnswer({ 1, v1, v2, N }, { 1, v2, v1, N });
	//system("Pause");
}