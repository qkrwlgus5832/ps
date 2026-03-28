#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <limits.h>
#include <algorithm>
#include <memory.h>

using namespace std;

int dir[4][2] = { {-1,0},{1,0}, {0,-1},{0,1} };
int curveddir[4][2] = {
	{'l', 'r'},
	{'r', 'l'},
	{'d','u' },
	{'u', 'd'}
};

int getDirIndex(char x) {
	if (x == 'u') {
		return 0;
	}
	if (x == 'd')
		return 1;
	if (x == 'l')
		return 2;
	if (x == 'r')
		return 3;
}
int rectangle[4] = { 0,0, 0, 0 };

void mapping(int i, int j) {
	rectangle[0] = max(rectangle[0], i);
	rectangle[1] = max(rectangle[1], j);
	rectangle[2] = min(rectangle[2], i);
	rectangle[3] = min(rectangle[3], j);
}
int main() {
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		string input;
		cin >> input;
		memset(rectangle, 0, sizeof(rectangle));

		int count = 0;
		int direction = 0;
		int i1 = 0;
		int j1 = 0;

		for (int i = 0; i < input.size(); i++) {
			
			if (input[i] == 'F') {
				count++;
				mapping(i1 + dir[direction][0] * count, j1 + dir[direction][1] * count);
			}
			if (input[i] == 'B') {
				count--;
				mapping(i1 + dir[direction][0] * count, j1 + dir[direction][1] * count);
			}
			if (input[i] == 'L') {
				i1 = i1 + dir[direction][0] * count;
				j1 = j1 + dir[direction][1] * count;
				mapping(i1, j1);
				direction = getDirIndex(curveddir[direction][0]);
				count = 0;
			}
			if (input[i] == 'R') {
				i1 = i1 + (dir[direction][0] * count);
				j1 = j1 + (dir[direction][1] * count);
				mapping(i1, j1);
				direction = getDirIndex(curveddir[direction][1]);
				count = 0;
			}
		}
		i1 = i1 + (dir[direction][0] * count);
		j1 = j1 + (dir[direction][1] * count);
		mapping(i1, j1);
		int xSize = rectangle[0] - rectangle[2];
		int ySize = rectangle[1] - rectangle[3];

		printf("%d\n", xSize * ySize);
	}
	//system("Pause");
}
