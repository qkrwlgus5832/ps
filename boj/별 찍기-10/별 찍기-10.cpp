#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;


string star[7000];
string star2[7000];
int N;

void recursion(int n) {
	if (n == 1)
		star[0] = "*";
	else {
		recursion(n / 3);

		string bla = "";
		for (int i = 0; i < n / 3; i++) {
			bla = bla + " ";
		}
		for (int i = n / 3; i < 2 * n / 3; i++) {
			star[i] = star[i - n / 3] + bla + star[i - n / 3];
		}

	}
	for (int i = 0; i < n / 3; i++) {
		star[i] = star[i] + star[i] + star[i];
	}

	for (int i = 2 * n / 3; i < n; i++) {
		star[i] = star[i - n * 2 / 3];
	}
}


int main() {
	cin >> N;

	recursion(N);
	for (int i = 0; i < N; i++) {
		printf("%s\n", star[i].c_str());

	}





}