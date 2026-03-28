#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;

vector <int> graph[201];
int N, M;
int result = 0;

void checkTrue(int x, int check[201]) {
	for (int i = 0; i < graph[x].size(); i++) {
		check[graph[x][i]]++;
	}

}

void checkFalse(int x, int check[201]) {
	for (int i = 0; i < graph[x].size(); i++) {
		check[graph[x][i]]--;
	}
}

void recursion(int index, vector <int> &combination, int check[201]) {
	if (combination.size() == 3) {
		result++;
		return;
	}
	for (int i = index; i <= N; i++) {
		if (check[i] == 0) {
			combination.push_back(i);
			checkTrue(i, check);
			recursion(i + 1, combination, check);
			combination.pop_back();
			checkFalse(i, check);
		}

	}

}

int main() {
	vector <int> combination;

	cin >> N >> M;
	int a, b;
	for (int i = 0; i < M; i++) {
		scanf("%d %d", &a, &b);
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	int check[201] = { false, };
	recursion(1, combination, check);
	cout << result;

	//system("Pause");
}
