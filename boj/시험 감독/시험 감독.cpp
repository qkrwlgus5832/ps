#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

int main() {
	int N;
	cin >> N;
	vector <int> v;

	int tmp;
	for (int i = 0; i < N; i++) {
		scanf("%d", &tmp);
		v.push_back(tmp);
	}
	int B, C;
	cin >> B >> C;

	long long result = 0;
	for (int i = 0; i < N; i++) {
		result++;
		if (v[i] > B) {
			v[i] -= B;
			result += (v[i] / C);
			if (v[i] % C != 0)
				result++;
		}
	}
	cout << result;
	//system("Pause");
}