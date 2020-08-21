#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

int check[61][61][61];

int result = INT_MAX;


int amount[6][3] = {
	{-9, -3, -1},
	{-9, -1, -3},
	{-3, -1, -9},
	{-3, -9, -1},
	{-1, -3, -9},
	{-1, -9, -3}
};

int dfs(vector <int> v) {
	for (int i = 0; i < v.size(); i++) {
		if (v[i] < 0) {
			v[i] = 0;
		}
	}
	
	if (check[v[0]][v[1]][v[2]] != -1) {
		return check[v[0]][v[1]][v[2]];
	}

	if (v[0] == 0 && v[1] == 0 && v[2] == 0) {
		check[v[0]][v[1]][v[2]] = 0;
		return 0;
	}

	int tmp = INT_MAX;

	for (int i = 0; i < 6; i++) {
		tmp = min(tmp, 1 + dfs({ v[0] + amount[i][0], v[1] + amount[i][1], v[2] + amount[i][2] }));
	}

	check[v[0]][v[1]][v[2]] = tmp;

	return tmp;
}



int main() {
	int N;
	cin >> N;

	vector <int> v;
	v.resize(3);

	for (int i = 0; i < N; i++) {
		scanf("%d", &v[i]);
	}

	memset(check, -1, sizeof(check));

	cout << dfs(v);

	//system("Pause");
}
