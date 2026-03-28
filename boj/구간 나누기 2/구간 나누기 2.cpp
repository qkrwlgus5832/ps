#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


vector <int> v;

int N, M;

bool isAnswer(int x) {
	int minValue = v[0];
	int maxValue = v[0];

	int count = 1;
	for (int i = 1; i < v.size(); i++) {
		minValue = min(minValue, v[i]);
		maxValue = max(maxValue, v[i]);

		if (maxValue - minValue > x) {
			count++;
			minValue = v[i];
			maxValue = v[i];
		}
	
	}
	if (count > M) {
		return false;
	}
	return true;
}


int binary_search(int start,int end) {
	if (start == end)
		return start;

	if (start + 1 == end) {
		if (isAnswer(start))
			return start;
		return end;
	}
	if (isAnswer((start + end) / 2)) {
		return binary_search(start, (start + end) / 2);
	}
	else {
		return binary_search((start + end) / 2 + 1, end);
	}
}

int main() {
	cin >> N >> M;
	v.resize(N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &v[i]);
	}

	cout << binary_search(0, 99999);

	//system("Pause");
}
