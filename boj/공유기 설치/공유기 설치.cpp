#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector <int> v;

bool isAnswer(int C, int distance) {
	int count = 2;
	int s = v.size();

	int tmp = v[0];

	if (v.size() == 2) {
		if (v[1] - v[0] >= distance)
			return true;
		return false;
	}
	for (int i = 1; i < v.size() - 1; i++) {
		if (v[i] - tmp >= distance && v[s - 1] - v[i] >= distance) {
			count++;
			tmp = v[i];
		}
		if (count >= C)
			return true;
	}
	return false;
}

int binary_search(int start, int end, int value) {
	if (start == end)
		return start;
	else if (start + 1 == end) {
		if (isAnswer(value, end))
			return end;
		return start;
	}

	if (isAnswer(value, (start + end) / 2) == false) {
		return binary_search(start, (start + end) / 2 - 1, value);
	}
	else
		return binary_search((start + end) / 2, end, value);

}

int main() {
	int N, C;
	cin >> N >> C;

	int tmp;
	for (int i = 0; i < N; i++) {
		scanf("%d", &tmp);
		v.push_back(tmp);
	}

	sort(v.begin(), v.end());

	cout << binary_search(0, 1000000000, C);
	//system("Pause");
}