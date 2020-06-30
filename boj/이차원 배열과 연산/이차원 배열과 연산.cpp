#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int graph[101][101];
int r, c, k;
int rowcount = 3;
int colcount = 3;

void C() {
	int count = 0;

	for (int j = 0; j < colcount; j++) {
		vector <pair <int, int>> v;

		int tmp[101] = { 0, };

		for (int i = 0; i < rowcount; i++) {

			if (graph[i][j] == 0)
				continue;
			
			tmp[graph[i][j]]++;
			graph[i][j] = 0;
		}

		for (int i = 1; i <= 100; i++) {
			if (tmp[i] > 0) {
				v.push_back(make_pair(tmp[i], i));
			}
		}
		sort(v.begin(), v.end());

		count = max(count, (int) v.size() * 2);

		for (int i1 = 0, i2 = 0; i1 < v.size(); i1++, i2 += 2) {
			if (i2 >= 100)
				break;
			graph[i2][j] = v[i1].second;
			if (i2 >= 99)
				break;
			graph[i2 + 1][j] = v[i1].first;
		}
	}
	rowcount = count;
}
void R() {
	int count = 0;
	for (int i = 0; i < rowcount; i++) {
		vector <pair <int, int>> v;
		int tmp[101] = { 0, };

		for (int j = 0; j < colcount; j++) {

			if (graph[i][j] == 0) {
				continue;
			}
			tmp[graph[i][j]]++;
			graph[i][j] = 0;
		}
		for (int i = 1; i <= 100; i++) {
			if (tmp[i] > 0) {
				v.push_back(make_pair(tmp[i], i));
			}
		}
		sort(v.begin(), v.end());

		count = max(count, (int)v.size() * 2);

		for (int i1 = 0, i2= 0; i1 < v.size(); i1++, i2+=2) {
			if (i2 >= 100)
				break;
			graph[i][i2] = v[i1].second;
			if (i2 >= 99)
				break;
			graph[i][i2+1] = v[i1].first;
		}
	}
	colcount = count;
}
int main() {

	cin >> r >> c >> k;
	r--; c--;

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			scanf("%d", &graph[i][j]);
		}
	}
	int time = 0;
	while (1) {
		if (time >= 101) {
			break;
		}
		if (graph[r][c] == k) {
			break;
		}
		if (rowcount >= colcount) {
			R();
		}
		else {
			C();
		}
		time++;
	}
	if (time > 100) {
		cout << -1;
	}
	else {
		cout << time;
	}
	//system("Pause");
}