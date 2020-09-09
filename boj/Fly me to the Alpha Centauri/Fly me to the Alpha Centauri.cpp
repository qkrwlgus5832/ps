#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;


long long getAnswer(long long distance) {
	long long count = 1;
	long long day = 1;

	while (1) {
		if (distance <= pow(count, 2)) {
			break;
		}
		day++;

		if (distance <= pow(count, 2) + count) {
			break;
		}
		count++; day++;
	}
	return day;
}

int main() {

	int T;
	cin >> T;
	
	for (int t = 0; t < T; t++) {
		long long x, y;
		cin >> x >> y;
		printf("%d\n", getAnswer(y - x));

	}
	//system("Pause");
}
