#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;


int main() {
	int N, M, K;
	cin >> N >> M >> K;
	
	int teamCount;

	int surplus;// ���� ��������� ���� �ο�

	if (M * 2 >= N) { // ���� * 2 �� ���� ������ ���ٸ�
		teamCount = N/ 2; // ���ڼ�/2 ��ŭ ���� ���������.
		surplus = M - (N / 2);  
	}
	else {
		teamCount = M;
		surplus = N - (2 * M);
	}
	if (surplus >= K)
		cout << teamCount;
	else {
		while (1) { // �׿� �ο��� K���� Ŀ���� ���� �ݺ�
			if (teamCount == 0)
				break;
			else if (surplus >= K)
				break;
			else {
				surplus += 3; // ���� ��ü���Ѽ� ����� ����
				teamCount--;
			}
		}
		cout << teamCount;
	}
	
	//system("Pause");
}
