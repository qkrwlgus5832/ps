#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>


using namespace std;

int N, M;

bool check[21][21][21][21];
char graph[21][21];

class coin {
public:
	int x;
	int y;
	coin() {};
	coin(int x, int y) {
		this->x = x;
		this->y = y;
	}
};

class coins {
public:
	coin firstCoin;
	coin secondCoin;

	coins(coin firstCoin, coin secondCoin) {
		this->firstCoin = firstCoin;
		this->secondCoin = secondCoin;
	}
};

int dir[4][2] = { {-1, 0}, { 1,0 }, { 0,-1 }, { 0,1 } };

coin getNext(coin &coin_, int dirIndex) {
	coin tmp = coin(coin_.x + dir[dirIndex][0], coin_.y + dir[dirIndex][1]);
	if (tmp.x < 0 || tmp.y < 0 || tmp.x >= N || tmp.y >= M)
		return tmp;
	if (graph[tmp.x][tmp.y] == '#')
		return coin_;
	return tmp;
}

int checkIfAnswer(const vector <coin> &v) {
	int count = 0;
	for (int i = 0; i < v.size(); i++) {
		if (v[i].x < 0 || v[i].y < 0 || v[i].x >= N || v[i].y >= M)
			count++;
	}
	return count;
}
int BFS(coin first, coin second) {
	queue <coins> q;

	q.push(coins(first, second));

	check[first.x][first.y][second.x][second.y] = true;
	check[second.x][second.y][first.x][first.y] = true;

	int length = 1;

	while (q.size()) {
		int s = q.size();
		for (int qs = 0; qs < s; qs++) {
			coins front = q.front();
			q.pop();


			for (int i1 = 0; i1 < 4; i1++) {
				first = getNext(front.firstCoin, i1);
				second = getNext(front.secondCoin, i1);


				if (checkIfAnswer({ first, second }) == 1)
					return length;
				else if (checkIfAnswer({ first, second }) == 2)
					continue;

				if (check[first.x][first.y][second.x][second.y])
					continue;

				check[first.x][first.y][second.x][second.y] = true;
				check[second.x][second.y][first.x][first.y] = true;
				q.push(coins(first, second));
			}
		}
		length++;
		if (length == 11)
			return -1;
	}
	return -1;
}
int main() {
	cin >> N >> M;

	vector <coin> v;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> graph[i][j];
			if (graph[i][j] == 'o') {
				v.push_back(coin(i, j));
			}
		}
	}

	cout << BFS(v[0], v[1]);
	//system("Pause");
}