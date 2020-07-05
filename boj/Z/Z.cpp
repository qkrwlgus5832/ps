#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <math.h>
using namespace std;
int graph[65][65];
int N;
int r;
int c;
int b;
int count1 = 0;
int f = 0;
void white(int x) {
	int a1 = x / b;
	int c1 = x % b;

	for (int i = a1; i <= a1 + 1; i++) {
		for (int j = c1; j <= c1 + 1; j++) {
			if (i == r && j == c)
				cout << count1;
			else
				count1 = count1 + 1;
		}
	}
}

int check(int x, int y, int x1, int y1) {

	if (x <= r && r < x1 && y <= c && c < y1)
		return 1;
	else
		return 0;
}

int Whroa(int x, int y, int x1, int y1) {
	if (x1 - x == 2)
		return x * b + y;
	int a = (x1 - x) / 2;
	if (check(x, y, x1 - a, y1 - a) == 1) {
		Whroa(x, y, x1 - a, y1 - a);
	}
	else if (check(x, y + a, x1 - a, y1) == 1) {
		count1 = count1 + ((x1 - x) / 2) * ((x1 - x) / 2);
		Whroa(x, y + a, x1 - a, y1);
	}
	else if (check(x + a, y, x1, y1 - a) == 1) {
		count1 = count1 + ((x1 - x) / 2) *((x1 - x) / 2) * 2;
		Whroa(x + a, y, x1, y1 - a);
	}
	else if (check(x + a, y + a, x1, y1) == 1) {
		count1 = count1 + ((x1 - x) / 2) *((x1 - x) / 2) * 3;
		Whroa(x + a, y + a, x1, y1);
	}
}


int main() {
	cin >> N >> r >> c;
	b = pow(2, N);
	//white(0, 0, b, b);
	int result = Whroa(0, 0, b, b);
	white(result);
}