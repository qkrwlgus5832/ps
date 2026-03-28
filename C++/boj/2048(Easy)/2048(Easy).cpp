#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <memory.h>

using namespace std;

int graph[21][21];


char dir[4] = { 'u', 'r', 'l', 'd' };
int N;
int result = 0;


vector <int> swipe(deque <int> &q) {
	vector <int> v;
	while (!q.empty()) {
		int front = q.front();
		q.pop_front();
		if (q.size() && front == q.front()) {
			q.pop_front();
			v.push_back(front + front);
		}
		else {
			v.push_back(front);
		}
		
	}
	return v;
}


void gaming(char dir) {
	if (dir == 'u') {
		for (int j = 0; j < N; j++) {
			deque <int> q;
			for (int i = 0; i < N; i++) {
				if (graph[i][j] != 0) {
					q.push_back(graph[i][j]);
					graph[i][j] = 0;
				}
			}
			vector <int> v = swipe(q);
			for (int i = 0; i < v.size(); i++) {
				graph[i][j] = v[i];
			}
		}
	}
	else if (dir == 'r') {
		for (int i = 0; i < N; i++) {
			deque <int> q;
			for (int j = N -1; j >=0; j--) {
				if (graph[i][j] != 0) {
					q.push_back(graph[i][j]);
					graph[i][j] = 0;
				}
			}
			vector <int> v = swipe(q);
			for (int j = N - 1, i1 = 0; i1 < v.size(); j--, i1++) {
				graph[i][j] = v[i1];
			}
		}
	}
	else if (dir == 'l') {
		for (int i = 0; i < N; i++) {
			deque <int> q;
			for (int j = 0; j < N; j++) {
				if (graph[i][j] != 0) {
					q.push_back(graph[i][j]);
					graph[i][j] = 0;
				}
			}
			vector <int> v = swipe(q);
			for (int j = 0; j < v.size(); j++) {
				graph[i][j] = v[j];
			}
		}
	}
	else if (dir == 'd') {
		for (int j = 0; j < N; j++) {
			deque <int> q;
			for (int i = N-1; i >=0; i--) {
				if (graph[i][j] != 0) {
					q.push_back(graph[i][j]);
					graph[i][j] = 0;
				}
			}
			vector <int> v = swipe(q);
			for (int i = N - 1, j1 = 0; j1 < v.size(); i--, j1++) {
				graph[i][j] = v[j1];
			}
		}
	}
}


void recursion(vector <char> v) {
	if (v.size() > 0) {
		gaming(v[v.size() - 1]);
		int tmpvalue = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				tmpvalue = max(tmpvalue, graph[i][j]);
			}
		}
		result = max(result, tmpvalue);
	}
	if (v.size() == 5) {
		return;
	}
	int tmpgraph[21][21] = { 0, };
	for (int i = 0; i < 4; i++) {
		v.push_back(dir[i]);
		memcpy(tmpgraph, graph, sizeof(graph));
		recursion(v);
		memcpy(graph, tmpgraph, sizeof(graph));
		v.pop_back();
	}
}
int main() {

	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &graph[i][j]);
		}
	}
	vector <char> v;
	recursion(v);
	cout << result;
	//system("Pause");

}