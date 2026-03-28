#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;

vector <int> v;


void manSwitching(int number) {
	for (int i = number; i < v.size(); i += number) {
		v[i] = !v[i];
	}
}

void womanSwitching(int number) {
	v[number] = !v[number];

	for (int i = 1; number + i < v.size() && number - i >= 1; i++) {
		if (v[number + i] == v[number - i]) {
			v[number + i] = !v[number + i];
			v[number - i] = !v[number - i];
		}
		else
			break;
	}
}
int main() {
	int N;
	cin >> N;

	v.resize(N + 1);

	int tmp;
	for (int i = 1; i <= N; i++) {
		scanf("%d", &v[i]);
	}
	int m;
	cin >> m;

	
	int s, n;

	for (int i = 0; i < m; i++) {
		scanf("%d %d", &s, &n);
		if (s == 1) {
			manSwitching(n);
		}
		else {
			womanSwitching(n);
		}
	}

	for (int i = 1; i < v.size(); i++) {
		if (i == v.size() - 1)
			printf("%d", v[i]);
		else {
			if (i > 20 && i % 20 == 1)
				printf("\n");
			printf("%d ", v[i]);
		}
	

	}
	//system("Pause");
}
