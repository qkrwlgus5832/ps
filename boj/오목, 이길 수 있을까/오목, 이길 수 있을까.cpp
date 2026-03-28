#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

char graph[11][11];


bool rowCheck(int i, int j) {
	int count = 0;
	for (int j1 = j; j1 >= 0; j1--) {
		if (graph[i][j1] == 'X')
			count++;
		else
			break;
	}

	for (int j1 = j + 1; j1 < 10; j1++) {
		if (graph[i][j1] == 'X')
			count++;
		else
			break;
	}
	return count >= 5;
}
bool colCheck(int i, int j) {
	int count = 0;
	for (int i1 = i; i1 >= 0; i1--) {
		if (graph[i1][j] == 'X')
			count++;
		else
			break;
	}

	for (int i1 = i + 1; i1 < 10; i1++) {
		if (graph[i1][j] == 'X')
			count++;
		else
			break;
	}
	return count >= 5;
}

bool leftToRight(int i, int j) {
	int count = 0;
	for (int i1 = i, j1 = j; i1 >= 0, j1 >= 0; i1--, j1--) {
		if (graph[i1][j1] == 'X') {
			count++;
		}
		else
			break;
	}

	for (int i1 = i + 1, j1 = j + 1; i1 < 10, j1 < 10; i1++, j1++) {
		if (graph[i1][j1] == 'X') {
			count++;
		}
		else
			break;

	}
	return count >= 5;
}

bool rightToLeft(int i, int j) {
	int count = 0;
	for (int i1 = i, j1 = j; i1 < 10, j1 >= 0; i1++, j1--) {
		if (graph[i1][j1] == 'X') {
			count++;
		}
		else
			break;
	}

	for (int i1 = i - 1, j1 = j + 1; i1 >= 0, j1 < 10; i1--, j1++) {
		if (graph[i1][j1] == 'X') {
			count++;
		}
		else
			break;

	}
	return count >= 5;
}
bool diagonalCheck(int i, int j) {
	return leftToRight(i, j) || rightToLeft(i, j);
}

bool checkIfAnswer() {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (graph[i][j] == '.') {
				graph[i][j] = 'X';
				if (rowCheck(i, j) || colCheck(i, j) || diagonalCheck(i, j))
					return true;
				graph[i][j] = '.';
			}
		}
	}
	return false;
}
int main() {

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			cin >> graph[i][j];
		}
	}
	
	cout << checkIfAnswer();
	
	//system("Pause");
}
