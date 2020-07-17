#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>

using namespace std;

long long N;
long long k;

long long aucqjsWo(long long x) {
	long long result = 0;
	long long tmp;
	for (int i = 1; i <= N; i++) {
		if (x%i == 0) {
			tmp = min(N, (x / i) - 1);
		}
		else if (x%i != 0)
			tmp = min(N, x / i);
		result = result + tmp;
	}

	return result + 1;
}


long long K(long long x) {
	for (int i = 1; i <= N; i++) {
		if (x%i == 0 && x <= i * N)
			return 1;
	}
	return 0;
}


long long bbinary_search(long long x, long long y, int x1) {
	if (x + 1 == y) {
		if (aucqjsWo(y) <= x1)
			return y;
		else
			return x;
	}
	else if (x == y)
		return x;
	long long tmp = aucqjsWo((x + y) / 2);
	if (tmp > x1)
		return bbinary_search(x, (x + y) / 2 - 1, x1);
	else if (tmp <= x1)
		return bbinary_search((x + y) / 2, y, x1);
}



int main() {
	cin >> N;
	cin >> k;
	long long result = bbinary_search(1, N*N, k);

	for (long long i = result; i >= 1; i--) {
		if (K(i) == 1) {
			printf("%lld", i);
			break;
		}

	}
}