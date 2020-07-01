#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <map>
#include <math.h>
#include <algorithm>
#include <queue>

using namespace std;

int d;
deque <int> number;
long long x, y;


pair <long long, long long> getLocation(long long x1, long long y1, long long size, deque <int> number) { // ��ġ�� ����
	if (number.size() == 0)
		return { x1,y1 };
	int current = number.at(0);
	number.pop_front();
	if (current == 1) {  //���� ���� Ž��
		return getLocation(x1 + size / 2, y1, size / 2, number);
	}
	else if (current == 2) { 
		return getLocation(x1, y1, size / 2, number);
	}
	else if (current == 3) {
		return getLocation(x1, y1 + size / 2, size / 2, number);
	}
	else if (current == 4) {
		return getLocation(x1 + size / 2, y1 + size / 2, size / 2, number);
	}
}

string find(pair <long long, long long> current, pair <long long, long long> dest, long long size, string result) {
	if (size == 1) {
		return result;
	}

	if (current.first <= dest.first && dest.first < current.first + size / 2) {
		if (current.second <= dest.second && dest.second < current.second + size / 2) { // 2�� ����
			return find(current, dest, size / 2, result + '2');
		}
		else {
			return find({ current.first, current.second + size / 2 }, dest, size / 2, result + '3'); // 3�� ����
		}
	}
	else {
		if (current.second <= dest.second && dest.second < current.second + size / 2) { // 1�� ����
			return find({ current.first + size / 2, current.second}, dest, size / 2, result + '1');
		}
		else {
			return find({ current.first + size / 2, current.second + size / 2 }, dest, size / 2, result + '4'); // 4�� ����
		}
	}

}
int main() {
	cin >> d;
	int tmp;
	for (int i = 0; i < d; i++) {
		scanf("%1d", &tmp);
		number.push_back(tmp);
	}
	cin >> x >> y;
	
	long long size = pow(2, d);

	pair <long long, long long> location = getLocation(0, 0, size, number); // ��и��� ������ location�� ã�´�.
	
	location.first += x;
	location.second += -1 * y; // ������ �ݴ�� ������

	if (location.first < 0 || location.second < 0 || location.first >= size || location.second >= size) { // ���� �ʰ�
		cout << -1;
	}
	else { // location�� ������ ��͸� Ÿ�� ��и��� ��ȣ�� ã�´�.
		cout << find({ 0,0 }, location, size, "");
	}

	//system("Pause");
}
