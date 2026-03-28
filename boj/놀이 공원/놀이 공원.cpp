#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>

using namespace std;

int N, M;

vector <int> v;

bool isAnswer(long long x, long long N) {
	long long count = 0;

	for (int i = 1; i <= M; i++) {
		count += x / v[i];
	}
	if (count < N)
		return false;
	return true;
}

long long binary_search(long long start, long long end, long long N) {

	if (start == end)
		return start;
	else if (start + 1 == end) {
		if (isAnswer(start,N))
			return start;
		return end; 
	}
	if (isAnswer((start + end) / 2, N)) {
		return binary_search(start, (start + end) / 2, N);
	}
	else {
		return binary_search((start + end) / 2 + 1, end, N);
	}

}

long long getIndex(long long x, long long y) {
	long long count1 = M;
	for (int i = 1; i <= M; i++) {
		count1 += x / v[i];
	}

	for (int i = 1; i <= M; i++) {
		if (y % v[i] == 0)
			count1++;
		if (count1 == N)
			return i;
	}

	return -1;
}
int main() {

	cin >> N >> M;

	v.resize(M + 1);
	for (int i = 1; i <= M; i++) {
		scanf("%d", &v[i]);
	}

	if (N - M <= 0) { // N이 M보다 작을 경우 그대로 출력해주면 된다.
		cout << N;
		return 0;
	}

	long long time = binary_search(0, 60000000000, N - M);// 최대는 20억 * 30이므로 600억
	cout << getIndex(time - 1, time);

	//system("Pause");
}

