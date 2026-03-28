#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

using namespace std;

string tmp;
long long DP[41];
int main() {

	cin >> tmp;
	if (tmp.at(0) - '0' == 0) {
		DP[0] = 0;
		cout << 0;
		return 0;
	}

	else
		DP[0] = 1;




	for (int i = 1; i < tmp.size(); i++) {

		DP[i] = DP[i - 1];
		int tmp1 = (tmp.at(i - 1) - '0') * 10 + (tmp.at(i) - '0');
		if (tmp1 == 0 || tmp1 == 40 || tmp1 == 50 || tmp1 == 60 || tmp1 == 70 || tmp1 == 80 || tmp1 == 90) {
			printf("0");
			return 0;
		}
		if (tmp1 == 10 || tmp1 == 20 || tmp1 == 30) {
			if (i == 1)
				DP[i] = 1;
			else
				DP[i] = DP[i - 2];
			continue;
		}

		if (i == 1) {

			if (tmp1 >= 10 && tmp1 <= 34)
				DP[i] = DP[i] + DP[i - 1];
		}
		else {
			if (tmp1 >= 10 && tmp1 <= 34)
				DP[i] = DP[i] + DP[i - 2];
		}


	}
	cout << DP[tmp.size() - 1];

}