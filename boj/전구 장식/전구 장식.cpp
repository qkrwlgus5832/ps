#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

vector <int> bulb;

int main() {
	int N;
	cin >> N;

	bulb.resize(N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &bulb[i]);
	}

	int previous = bulb[0];
	int count = 1;

	vector <int> pattern;

	for (int i = 1; i < N; i++) {
		if (bulb[i] != previous) {
			count++;
		}
		else {
			pattern.push_back(count);
			count = 1;
		}
		previous = bulb[i];
	}
	pattern.push_back(count);

	int maxLength = 0;

	for (int i = 0; i < pattern.size(); i++) {
		int length = 0;
		for (int j = 0; j < 3; j++) {
			if (i + j < pattern.size() )
				length += pattern[i + j];
		}
		maxLength = max(maxLength, length);
	}
	cout << maxLength;
	//system("Pause");
}
