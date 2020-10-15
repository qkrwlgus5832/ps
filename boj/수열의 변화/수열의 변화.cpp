#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

void getB(vector <int>& v) {
	for (int i = 0; i < v.size() - 1; i++) {
		v[i] = v[i + 1] - v[i];
	}
	v.pop_back();

}

int main() {
	int N, K;
	cin >> N >> K;

	vector <int> v;
	string input;
	cin >> input;

	int tmp = 0;
	int minusFlag = 1;

	for (int i = 0; i < input.size(); i++) {
		if (input[i] == ',') {
			v.push_back(tmp * minusFlag);
			minusFlag = 1;
			tmp = 0;
		}
		else if (input[i] == '-') {
			minusFlag = -1;
		}
		else {
			tmp = tmp * 10 + (input[i] - '0');
		}
	}
	v.push_back(minusFlag * tmp);

	for (int i = 0; i < K; i++) {
		getB(v);
	}
	for (int i = 0; i < v.size(); i++) {
		if (i == v.size() - 1) {
			printf("%d", v[i]);
		}
		else
			printf("%d,", v[i]);
	}
	//system("Pause");
}
