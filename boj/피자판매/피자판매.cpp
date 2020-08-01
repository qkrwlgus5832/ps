#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <map>

using namespace std;

int whole;

vector <int> A;
vector <int> B;

map <long long, long long> m;


void checkMap() {
	m[0] = 1;
	for (int i = 0; i < B.size(); i++) {
		long long tmp = 0;
		for (int i1 = i; i1 < B.size(); i1++) {
			tmp += B[i1];
			m[tmp]++;

		}

		for (int i1 = 0; i1 < i - 1; i1++) {
			tmp += B[i1];
			m[tmp]++;
		}

	}
}

long long getAnswer() {
	long long answer = 0;
	for (int i = 0; i < A.size(); i++) {
		long long tmp = 0;
		for (int i1 = i; i1 < A.size(); i1++) {
			tmp += A[i1];
			answer += m[whole - tmp];

		}
		for (int i1 = 0; i1 < i - 1; i1++) {
			tmp += A[i1];
			answer += m[whole - tmp];
		}
	}
	return answer + m[whole];
}
int main() {
	cin >> whole;

	int m, n;
	cin >> m >> n;

	A.resize(m);
	B.resize(n);

	for (int i = 0; i < m; i++) {
		scanf("%d", &A[i]);
	}
	for (int i = 0; i < n; i++) {
		scanf("%d", &B[i]);
	}

	checkMap();
	cout << getAnswer();
	//system("Pause");
}