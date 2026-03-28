#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int winlose[10][10];


int N, K;

bool result = false;

pair <int, int> fight(int winner, int other, deque <deque <int>>& v) {
	int winnerIndex = v[winner].front();
	int otherIndex = v[other].front();

	v[winner].pop_front();
	v[other].pop_front();

	if (winlose[winnerIndex][otherIndex] == 2) {
		return make_pair(winner, other);
	}
	else if (winlose[winnerIndex][otherIndex] == 1) {
		if (other > winner) {
			return make_pair(other, winner);
		}
		return make_pair(winner, other);
	}
	else {
		return make_pair(other, winner);
	}
}
bool simulation(deque <int> j, deque <int> g, deque <int> m) {
	deque <deque <int>> v;
	v.push_back(j);
	v.push_back(g);
	v.push_back(m);

	int winner = 0;
	int other = 1;
	int loser = 2;

	int check[3] = { 0, };

	while (1) {
		if (v[0].size() == 0 || v[1].size() == 0 || v[2].size() == 0) {
			return false;
		}
		pair <int, int> tmp = fight(winner, other, v);

		winner = tmp.first;
		check[winner]++;
		if (check[winner] >= K) {
			if (winner == 0)
				return true;
			else
				return false;
		}

		other = loser;
		loser = tmp.second;

	}
	return false;
}
void DFS(deque <int> v, deque <int> g, deque <int> m, bool check[10]) {
	if (v.size() == N) {
		result = result || simulation(v,g,m);
		return;
	}
	for (int i = 1; i <= N; i++) {
		if (check[i] == false) {
			v.push_back(i);
			check[i] = true;
			DFS(v, g, m, check);
			check[i] = false;
			v.pop_back();
		}
	}
}

int main() {

	cin >> N >> K;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			scanf("%d", &winlose[i][j]);
		}
	}

	int a;

	deque <int> g;
	deque <int> m;

	for (int i = 0; i < 20; i++) {
		scanf("%d", &a);
		g.push_back(a);
	}
	for (int i = 0; i < 20; i++) {
		scanf("%d", &a);
		m.push_back(a);
	}
	
	deque <int> v;
	bool check[10] = { false, };
	DFS(v,g,m, check);
	cout << result;
	//system("Pause");
}