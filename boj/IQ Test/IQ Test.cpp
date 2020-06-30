#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <vector>
#include <map>

using namespace std;

vector <int> A;

int getAnswer(int a, int b, int beforevalue) {
	return a * beforevalue + b;
}

pair <int,int> getAandB(int firstValue, int secondValue, int thirdValue) {
	int tmp = secondValue - firstValue;
	int value = thirdValue - secondValue;

	if (tmp != 0 && value % tmp == 0) {
		int a = value / tmp;
		return { a, secondValue - (firstValue * a) };
	}
	else if (tmp == 0 && secondValue == thirdValue)
		return { 1,0 };

	cout << "B";
	exit(0);
}

int main() {
	int N;
	cin >> N;
	int tmp;

	for (int i = 0; i < N; i++) {
		scanf("%d", &tmp);
		A.push_back(tmp);
	}
	
	if (N == 1) {
		cout << "A";
	}
	else if (N == 2) {
		if (A[0] == A[1]) 
			cout << A[0];
		else
			cout << "A";
	}
	else {
		pair <int, int> AB = getAandB(A[0], A[1], A[2]);
		for (int i = 3; i < N; i++) {
			if (A[i] != A[i - 1] * AB.first + AB.second) {
				cout << "B";
				exit(0);
			}
		}
		cout << A[A.size() - 1] * AB.first + AB.second;
	}
	
	//system("Pause");

}