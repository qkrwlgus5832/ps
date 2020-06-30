#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <limits.h>
#include <vector>
#include <algorithm>

using namespace std;

int result = INT_MAX;
int graph[21][21];
int N;
bool check[21];


int calculate() {
	int teams[2] = { 0, };
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (i == j)
				continue;
			if (check[i] == check[j]) {
				if (check[i] == false) {
					teams[0] += graph[i][j];
				}
				else {
					teams[1] += graph[i][j];
				}
			}
		}
	}
	return abs(teams[1] - teams[0]);
}


void recursion(vector <int> v, int index) {
	if (v.size() == N / 2) {
		result = min(result,calculate());
		return;
	}
	for (int i = index; i < N; i++) {
		if (check[i] == false) {
			check[i] = true;
			v.push_back(i);
			recursion(v, i+1);
			check[i] = false;
			v.pop_back();
		}

	}
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &graph[i][j]);
		}
	}
	vector <int> v;
	
	recursion(v, 0);
	cout << result;
	//system("Pause");
}