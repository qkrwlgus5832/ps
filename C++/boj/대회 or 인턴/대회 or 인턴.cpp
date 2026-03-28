#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;


int main() {
	int N, M, K;
	cin >> N >> M >> K;
	
	int teamCount;

	int surplus;// 팀이 만들어지고 남은 인원

	if (M * 2 >= N) { // 남자 * 2 가 여자 수보다 많다면
		teamCount = N/ 2; // 여자수/2 만큼 팀이 만들어진다.
		surplus = M - (N / 2);  
	}
	else {
		teamCount = M;
		surplus = N - (2 * M);
	}
	if (surplus >= K)
		cout << teamCount;
	else {
		while (1) { // 잉여 인원이 K보다 커질때 까지 반복
			if (teamCount == 0)
				break;
			else if (surplus >= K)
				break;
			else {
				surplus += 3; // 팀을 해체시켜서 사람을 얻음
				teamCount--;
			}
		}
		cout << teamCount;
	}
	
	//system("Pause");
}
