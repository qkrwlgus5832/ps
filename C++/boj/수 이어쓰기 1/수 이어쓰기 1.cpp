#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <algorithm>
#include <math.h>

using namespace std;

long long N;

int main() {
	cin >> N;
	string input = to_string(N);

	long long tmp = 9;
	long long digitCount = 0;

	for (int i = 1; i < input.size(); i++) {
		digitCount += tmp * i;
		tmp *= 10;
	}

	long long standard = pow(10, input.size() - 1) - 1;
	digitCount += (N - standard) * input.size();
	cout << digitCount;
	//system("Pause");
}