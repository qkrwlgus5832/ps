#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;


bool checkIfAnswer(map <int, int>& m, map <int, int>& m2) {
	if (m.size() == 0 && m2.size() == 0)
		return true;

	for (auto iter = m.begin(); iter != m.end(); iter++) {
		if (iter->second != 1)
			return false;
	}
	int count = 0;

	for (auto iter = m2.begin(); iter != m2.end(); iter++) {
		if (m[iter->first] == 0)
			count++;
		else if (m[iter->first] != 1)
			return false;

	}
	if (count == 1)
		return true;
	return false;
}

int find(int x, map <int, int>& unionFind) {
	if (unionFind[x] == 0) {
		return x;
	}
	int parent = find(unionFind[x], unionFind);
	unionFind[x] = parent;
	return parent;
}

void merge(int a, int b, map <int, int>& unionFind) {
	unionFind[b] = a;
}
int main() {
	int u, v;

	int caseCount = 1;

	while (1) {
		map <int, int> m;
		map <int, int> m2;
		map <int, int> unionFind;
		bool flag = true;

		while (1) {
			scanf("%d %d", &u, &v);

			if (u == 0 && v == 0)
				break;
			if (u < 0 && v < 0)
				return 0;

			int parentU = find(u, unionFind);
			int parentV = find(v, unionFind);

			if (parentU == parentV) {
				flag = false;
			}

			merge(u, v, unionFind);

			m[v]++;
			m2[u]++;


		}

		if (flag && checkIfAnswer(m, m2))
			printf("Case %d is a tree.\n", caseCount);
		else
			printf("Case %d is not a tree.\n", caseCount);

		caseCount++;
	}


	//system("Pause");
}
