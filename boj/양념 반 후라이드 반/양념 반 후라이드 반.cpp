#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <limits.h>

using namespace std;

int A, B, C;
int X, Y;

int getAnswer(int chicken1, int chicken2, int tmp) {
	if (X > chicken1) {
		tmp += (X - chicken1) * A;
	}
	if (Y > chicken2) {
		tmp += (Y - chicken2) * B;
	}

	return tmp;
}
int main() {
	cin >> A >> B >> C >> X >> Y;

	int result = INT_MAX;

	for (int i = 0; i <= max(X, Y) * 2; i += 2) { // X,Y�� �����̹Ƿ� 0.5������ �ǹ̰� ����.
		 // �ݹݼ�Ʈ�� ä�� �� ���� ��ŭ ä������.

		int tmp = C * i;
		
		int chicken1 = i / 2;
		int chicken2 = i / 2;

		result = min(result, getAnswer(chicken1, chicken2, tmp));
	}
	cout << result;
	//system("Pause");
}
