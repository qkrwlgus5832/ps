#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>


using namespace std;

long long DP[31][31];

long long recursion(int w, int h) {
	if (w == 0) {
		return 1;
	}
	long long tmp = 0;
	if (w > 0) {
		if (DP[w - 1][h + 1] > 0) {
			tmp += DP[w - 1][h + 1];
		}
		else
			tmp += recursion(w - 1, h + 1);
	}
	if (h > 0) {
		if (DP[w][h - 1] > 0) {
			tmp += DP[w][h - 1];
		} 
		else {
			tmp += recursion(w, h - 1);
		}
	}
	DP[w][h] = tmp;
	return tmp;
}

int main() {
	int T;
	int tmp;

	for (;;) {
		scanf("%d", &tmp);
		if (tmp == 0)
			break;
		printf("%lld\n" , recursion(tmp, 0));
	}
	//system("Pause");
}