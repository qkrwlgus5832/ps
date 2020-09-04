#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

unordered_map <int, unordered_map <int, bool>> m;

int a, b, c, d;

queue <pair <int, int>> q;

void queuepush(const pair <int, int>& currentWater) {
	if (m[currentWater.first][currentWater.second] == false) {
		m[currentWater.first][currentWater.second] = true;
		q.push(currentWater);
	}
}
void fillX(int x, int y) {
	queuepush({ a, y });
}

void EmptyX(int x, int y) {
	queuepush({ 0, y });
}

void fillY(int x, int y) {
	queuepush({ x, b });
}

void EmptyY(int x, int y) {
	queuepush({ x, 0 });
}

void moveXtoY(int x, int y) {
	if (b - y >= x) {
		queuepush({ 0, x + y });
	}
	else {
		queuepush({ x - (b - y) , b });
	}
}

void moveYtoX(int x, int y) {
	if (a - x >= y) {
		queuepush({ x+ y, 0 });
	}
	else {
		queuepush({ a , y - (a-x) });
	}
}
int BFS() {
	m[0][0] = true;
	
	q.push({ 0,0 });

	int length = 0;

	while (q.size()) {
		int s = q.size();
		for (int qs = 0; qs < s; qs++) {
			pair <int, int> front = q.front();
			int x = front.first; int y = front.second;
			if (x == c && y == d)
				return length;
			q.pop();
			fillX(x,y);
			fillY(x, y);
			EmptyX(x, y);
			EmptyY(x, y);
			moveXtoY(x, y);
			moveYtoX(x, y);

		}

		length++;
	}
	return -1;
}


int main() {

	cin >> a >> b >> c >> d;
	cout << BFS();

	//system("Pause");
}
