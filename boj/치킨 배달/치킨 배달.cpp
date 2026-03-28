#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
#include <algorithm>

using namespace std;

int N, M;

vector <pair <int, int>> home;
vector <pair <int, int>> chicken;

vector <vector <pair <int, int>>> chickendistance;

int graph[51][51];
int result = INT_MAX;

int calculate() {
	int length = 0;

	for (int i = 0; i < home.size(); i++) {
		for (int j = 0; j < chickendistance[i].size(); j++) {
			int chickenIndex = chickendistance[i][j].second;
			if (graph[chicken[chickenIndex].first][chicken[chickenIndex].second] == 3) {
				length += chickendistance[i][j].first;
				break;
			}
		}
	}
	return length;
}
void recursion(int i, int count) {
	if (count == M) {
		result = min(result, calculate());
		return;
	}
	for (int index = i; index < chicken.size(); index++) {
		graph[chicken[index].first][chicken[index].second] = 3;
		recursion(index + 1, count + 1);
		graph[chicken[index].first][chicken[index].second] = 2;
	}
}

int main() {
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &graph[i][j]);
			if (graph[i][j] == 1) {
				home.push_back(make_pair(i, j));
			}
			else if (graph[i][j] == 2) {
				chicken.push_back(make_pair(i, j));
			}
		}
	}

	chickendistance.resize(251);

	for (int i = 0; i < home.size(); i++) {
		for (int j = 0; j < chicken.size(); j++) {
			int distance = abs(home[i].first - chicken[j].first) + abs(home[i].second - chicken[j].second);
			chickendistance[i].push_back(make_pair(distance, j));
		}
		sort(chickendistance[i].begin(), chickendistance[i].end());
	}
	recursion(0, 0);
	cout << result;
	//system("Pause");
}