#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <queue>
#include <algorithm>
#include <map>

using namespace std;

deque <int> v;

int main() {
	int N;
	cin >> N;
	v.resize(N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &v[i]);
	}
	sort(v.begin(), v.end());

	if (v[0] != 1) {
		cout << 1;
		return 0;
	}

	long long size = 1;

	v.pop_front();

	for (int current : v) {
		if (size + 1 == current) {
			size = current + size;
			continue;
		}
		if (current > size) {
			break;
		}

		size = size + current;

	}
	cout << size + 1;
	//system("Pause");
}
