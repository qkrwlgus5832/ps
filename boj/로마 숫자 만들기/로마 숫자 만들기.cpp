#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <map>

using namespace std;

int N;

int T[4] = { 1,5,10,50 };

map <int, int> m;
int result = 0;
void recursion(int count, int value, int index) {
	if (count == N) {
		if (m.count(value) == 0) {
			m[value] = 1;
			result++;
		}
		return;
	}
	for (int i = index; i < 4; i++) {
		recursion(count + 1, value + T[i], i);
	}
}

int main() {
	cin >> N;
	recursion(0, 0, 0);

	cout << result;
	//system("Pause");
}