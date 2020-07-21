#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

vector <int> v;


int main() {
	int N;
	cin >> N;
	
	v.resize(N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &v[i]);
	}

	sort(v.begin(), v.end());

	long long result = 0;

	for (int i = 0; i < v.size(); i++) {
		result += abs(v[i] - (i + 1));
	}
	cout << result;
	//system("Pause");
}
