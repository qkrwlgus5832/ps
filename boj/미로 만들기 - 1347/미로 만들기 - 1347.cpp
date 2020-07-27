#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

bool check[101][101];


map <char, vector <char>> direction;

void init() {
	direction['u'] = { 'l', 'r' };
	direction['l'] = { 'd', 'u' };
	direction['r'] = { 'u', 'd' };
	direction['d'] = { 'r', 'l' };
}

pair <int, int> makeLocation(char dir) {
	if (dir == 'u')
		return { -1,0 };
	if (dir == 'd')
		return { 1,0 };
	if (dir == 'l')
		return { 0, -1 };
	return { 0,1 };
}

void update(int &left, int &right, int &top, int &bottom, int x, int y) {
	left = min(left, y);
	right = max(right, y);
	top = min(top, x);
	bottom = max(bottom, x);
}
int main() {
	int length;
	cin >> length;

	string input;
	cin >> input;

	init();
	check[50][50] = true;
	
	int left = 50, right = 50, top = 50, bottom = 50;

	char dir = 'd';
	int x = 50,  y = 50;

	for (char current : input) {
		if (current == 'L') {
			dir = direction[dir][0];
		}
		else if (current == 'R') {
			dir = direction[dir][1];
		}
		else {
			pair <int, int> tmp = makeLocation(dir);
			x = x + tmp.first;
			y = y + tmp.second;
			check[x][y] = true;
			update(left, right, top, bottom, x, y);
		}
	}

	for (int i = top; i <= bottom; i++) {
		for (int j = left; j <= right; j++) {
			if (check[i][j] == false)
				cout << '#';
			else
				cout << '.';
		}
		cout << endl;
	}
//	system("Pause");
}

