#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;


long long dp[100][10][1 << 10];

int mod = 1000000000;

void dfs(int size, int number, int check);

int getBitmask(int check, int number) {
	return check | (1 << number);
}

void controller(int size, int current, int next, int currentCheck, int nextCheck) {
	if (dp[size - 1][next][nextCheck] == 0) {
		dfs(size - 1, next, nextCheck);
	}
	dp[size][current][currentCheck] += dp[size - 1][next][nextCheck] % mod;
}
void dfs(int size, int number, int check) {
	
	if (size == 0) {
		if (number != 0 && check == ((1 << 10) - 1))
			dp[size][number][check] = 1;
		return;
	}
	if (number- 1 >=0){
		controller(size, number, number -1, check, getBitmask(check, number - 1));
	}
	if (number +1 <=  9) {
		controller(size, number, number+1, check, getBitmask(check, number + 1));
	}

}
int main() {

	int N;
	cin >> N;

	long long ans = 0;

	for (int i = 0; i <= 9; i++) {
		dfs(N - 1, i, 1 << i);
		ans = (ans + dp[N - 1][i][1 << i]) % mod;
	}

	cout << ans;
	//system("Pause");
}
