#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int R, B;

bool isAnswer(int L , int W) {
	int rCount = L * 2 + W * 2 - 4;
	int bCount = L * W - rCount;

	if (R == rCount && B == bCount)
		return true;
	return false;
}


pair <int ,int> getAnswer(int tiles) {

	for (int i = 1; i <= tiles / 2; i++) {
		if (tiles % i == 0) {
			if (isAnswer(tiles / i, i))
				return { tiles / i, i };
		}
	}
	return { tiles, 1 };
}


int main() {
	cin >> R >> B;
	pair <int, int> result = getAnswer(R + B);
	cout << result.first <<" " <<  result.second;
	//system("Pause");
}
