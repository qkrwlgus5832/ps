#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector <int> T; 
vector <int> output;


int switching(int N, int switchCount, vector <int> input) { // �� �� ������ output�ϰ� �ٸ��ٸ� �ٲ��ش�.

	for (int i = 1; i < N; i++) {
		if (input[i - 1] != output[i - 1]) {
			input[i - 1] = !input[i - 1];
			input[i] = !input[i];
			if (i != N-1) {
				input[i + 1] = !input[i + 1];
			}
			switchCount++;
		}

	}
	if (input[N - 1] == output[N - 1])
		return switchCount;
	return -1;
}

int main() {
	int N;
	cin >> N;

	T.resize(N);
	output.resize(N);

	for (int i = 0; i < N; i++) {
		scanf("%1d", &T[i]);
	}
	for (int i = 0; i < N; i++) {
		scanf("%1d", &output[i]);
	}

	int resultCandidate1 = switching(N, 0, T); // ù��° ������ ����ġ ���� ���
	T[0] = !T[0]; 
	T[1] = !T[1];
	int resultCandidate2 = switching(N, 1, T); // ù��° ������ ����ġ�� ���

	if (resultCandidate1 == -1 && resultCandidate2 == -1) {
		cout << -1;
	}
	else if (resultCandidate1 == -1){
		cout << resultCandidate2;
	}
	else if (resultCandidate2 == -1) {
		cout << resultCandidate1;
	}
	else {
		cout << min(resultCandidate1, resultCandidate2); // �Ѵ� -1�� �ƴ϶�� ���� �ּҰ��� ���
	}

	//system("Pause");
}
