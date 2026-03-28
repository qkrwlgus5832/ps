#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector <pair <int, int>> sticker;
int result = 0;
int H, W;

int getArea(pair <int, int> sticker1, pair <int, int> sticker2) { // 두개의 스티커로 구할 수 있는 최대 넓이를 구한다.

	if (sticker1.first + sticker2.first > H || sticker1.second > W || sticker2.second > W) { // 최대 높이, 최대 너비를 넘어가는 경우 0을 리턴한다.
		if (sticker1.first > H || sticker2.first > H || sticker1.second + sticker2.second > W) {
			return 0;
		}
	}
	return sticker1.first * sticker1.second + sticker2.first * sticker2.second;
}

pair <int, int> getSwaped(pair <int, int> sticker) { // swap된 좌표를 구한다.
	return { sticker.second, sticker.first };
}

void getAnswer(vector <int> v) {
	int index1 = v[0];
	int index2 = v[1];
	
	result = max(result, getArea(sticker[index1], sticker[index2])); // 모든 경우의 수를 구한다.
	result = max(result, getArea(getSwaped(sticker[index1]), sticker[index2]));
	result = max(result, getArea(sticker[index1], getSwaped(sticker[index2])));
	result = max(result, getArea(getSwaped(sticker[index1]), getSwaped(sticker[index2])));
}

void combination(int index, vector <int> v) { // 조합으로 중복되지 않는 2개의 스티커를 뽑는다.
	if (v.size() == 2) {
		getAnswer(v);
		return;
	}
	for (int i = index; i < sticker.size(); i++) {
		v.push_back(i);
		combination(i + 1, v);
		v.pop_back();
	}
}

int main() {

	cin >> H >> W;
	int N;
	cin >> N;

	int r, c;
	for (int i = 0; i < N; i++) {
		scanf("%d %d", &r, &c);
		sticker.push_back({ r,c });

	}

	vector <int> v;
	combination(0, v);

	cout << result;
	//system("Pause");
}
