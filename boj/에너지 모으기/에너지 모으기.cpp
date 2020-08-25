#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;


vector <int> v;
bool check[11];
int result = 0;

void recursion(vector <int> v, int sum) {
	if (v.size() == 2) {
		result = max(sum, result);
		return;
	}

	for (int i = 1; i < v.size() - 1; i++) {
		int tmp = v[i];
		int energe = v[i - 1] * v[i + 1];
		v.erase(v.begin() + i);
		recursion(v, sum + energe);
		v.insert(v.begin() + i, tmp);
	}
}

int main() {
	int N;
	cin >> N;

	v.resize(N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &v[i]);
	}

	recursion(v, 0);
	cout << result;

	//system("Pause");
}
