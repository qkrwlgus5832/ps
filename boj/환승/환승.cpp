#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int N, K, M;

vector <int> node[100001];
vector <int> hyper[1001];



int BFS(int i) {
	bool nodeCheck[100001] = { false, };
	bool hyperCheck[1001] = { false, };

	queue <int> q;

	nodeCheck[i] = true;

	q.push(i);
	int level = 1;

	while (q.size()) {
		int s = q.size();
		for (int qs = 0; qs < s; qs++) {
			int front = q.front();
			q.pop();

			if (front == N)
				return level;

			for (int i = 0; i < node[front].size(); i++) {
				if (hyperCheck[node[front][i]] == false) {
					hyperCheck[node[front][i]] = true;
					int hyperIndex = node[front][i];
					for (int i1 = 0; i1 < hyper[hyperIndex].size(); i1++) {
						if (nodeCheck[hyper[hyperIndex][i1]] == false) {
							nodeCheck[hyper[hyperIndex][i1]] = true;
							q.push(hyper[hyperIndex][i1]);
						}
					}
				}
			}

		}
		level++;
	}
	return -1;
}

int main() {

	cin >> N >> K >> M;
	int tmp;
	for (int i = 0; i < M; i++) {
		vector <int> input;
		for (int j = 0; j < K; j++) {
			scanf("%d", &tmp);
			node[tmp].push_back(i);
			hyper[i].push_back(tmp);
		}
	}

	cout << BFS(1);
	//system("Pause");

}