#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;


bool check[11];

int minResult = INT_MAX;


int N;
int NSize = 0;


void recursion(int number, int count) {

	if (count !=0 && minResult > abs(N - number) + count) {
		minResult = abs(N - number) + count;
	}

	if (count >= NSize + 1) {
		return;
	}

	if (count==0 || number != 0){
		for (int i = 0; i <= 9; i++) {
			if (check[i] == false) {
				recursion(number * 10 + i, count + 1);
			}
		}
	}
}


int main() {

	cin >> N;

	int M;
	cin >> M;

	int input;
	for (int i = 0; i < M; i++) {
		cin >> input;
		check[input] = true;
	}
	NSize = to_string(N).size();

	recursion(0, 0);

		
	cout << min(minResult, abs(100 - N));
	//system("Pause");
}
