#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


vector <int> v;
int N;

int main() {
	cin >> N;


	v.resize(N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &v[i]);

	}
	sort(v.begin(), v.end());

	long long result = 0;
	int current = 0;

	for (int tmp : v) {
		current += tmp;
		result += current;
	}
	cout << result;
	//system("Pause");
}