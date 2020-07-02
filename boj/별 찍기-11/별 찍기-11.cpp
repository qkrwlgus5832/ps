#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

string star[10000];

void recursion(int n) {

	if (n == 3) {
		star[0] = "*";
		star[1] = "* *";
		star[2] = "*****";
		return;
	}

	else {
		recursion(n / 2);
		int b = n / 2;
		string bla = "";

		int c = star[n / 2 - 1].size();

		for (int i = 0; i < c; i++) {
			bla = bla + " ";
		}

		for (int i = n / 2; i < n; i++) {
			star[i] = star[i - b] + bla + star[i - b];
			bla.erase(0, 2);

		}

	}


}


int main() {

	int N;
	cin >> N;

	recursion(N);
	string bla = "";

	for (int j = 0; j < N - 1; j++) {
		bla = bla + " ";
	}
	for (int i = 0; i < N; i++) {
		string d = bla + star[i] + bla;
		printf("%s\n", d.c_str());
		bla.erase(0, 1);
	}


}


