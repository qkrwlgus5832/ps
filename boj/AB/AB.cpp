#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <limits.h>
#include <string>

using namespace std;

pair <int, int> getABCount(int N, int K) {
	int minValue = INT_MAX;
	int ACount = 0;
	int BCount = 0;
	for (int i = 1; i <= K; i++) { // 1부터 K까지 계속 나눠가며 확인함
		int tmpA = i;
		int tmpB = K / i;
		if (K % i != 0)
			tmpB++;

		if (tmpA + tmpB < minValue) { // 최소를 찾아준다.
			minValue = tmpA + tmpB;
			ACount = tmpA;
			BCount = tmpB;
		}
	}
	return { ACount, BCount };
}

void addChartoString(int count, char ch, string &s) {
	string tmp = "";
	for (int i = 0; i < count; i++) {
		tmp += ch;
	}
	s = tmp + s;
}
int main() {
	int N, K;
	cin >> N >> K;

	if (K == 0) {
		for (int i = 0; i < N; i++) {
			printf("B");     // K가 0이면 B나 A를 다출력해주면 된다.
		}
		return 0;
	}
	pair <int, int> AB = getABCount(N, K);
	if (AB.first + AB.second > N) {
		cout << -1;
	}
	else {
		string result = "";
		if (K % AB.first != 0) {
			int BCount = AB.second - 1; 
			int ACountMax = K % AB.first; // 나머지때문에 +1씩 해줘야하는 개수
			int ACountMin = AB.first - ACountMax; // A개수 - AcountMax

			addChartoString(BCount, 'B', result);
			addChartoString(ACountMin, 'A', result);
			addChartoString(1, 'B', result);
			addChartoString(ACountMax, 'A', result);

		}
		else {
			int BCount = AB.second;
			int ACount = AB.first;
	
			addChartoString(BCount, 'B', result);
			addChartoString(ACount, 'A', result);
		}
		for (int i = 0; i < N - result.size(); i++) { // 남는 자리는 B로 채워준다.
			printf("B");
		}
		cout << result;

	}
	//system("Pause");
}
