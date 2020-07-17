#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector <pair <int, int>> sticker;
int result = 0;
int H, W;

int getArea(pair <int, int> sticker1, pair <int, int> sticker2) { // �ΰ��� ��ƼĿ�� ���� �� �ִ� �ִ� ���̸� ���Ѵ�.

	if (sticker1.first + sticker2.first > H || sticker1.second > W || sticker2.second > W) { // �ִ� ����, �ִ� �ʺ� �Ѿ�� ��� 0�� �����Ѵ�.
		if (sticker1.first > H || sticker2.first > H || sticker1.second + sticker2.second > W) {
			return 0;
		}
	}
	return sticker1.first * sticker1.second + sticker2.first * sticker2.second;
}

pair <int, int> getSwaped(pair <int, int> sticker) { // swap�� ��ǥ�� ���Ѵ�.
	return { sticker.second, sticker.first };
}

void getAnswer(vector <int> v) {
	int index1 = v[0];
	int index2 = v[1];
	
	result = max(result, getArea(sticker[index1], sticker[index2])); // ��� ����� ���� ���Ѵ�.
	result = max(result, getArea(getSwaped(sticker[index1]), sticker[index2]));
	result = max(result, getArea(sticker[index1], getSwaped(sticker[index2])));
	result = max(result, getArea(getSwaped(sticker[index1]), getSwaped(sticker[index2])));
}

void combination(int index, vector <int> v) { // �������� �ߺ����� �ʴ� 2���� ��ƼĿ�� �̴´�.
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
