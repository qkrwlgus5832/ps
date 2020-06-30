#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <vector>
#include <map>

using namespace std;


class robot {
public:
	int x = -1;
	int y = -1;
	int index = -1;
	char dir;

	robot(int x, int y, int index, char dir) {
		this->x = x;
		this->y = y;
		this->index = index;
		this->dir = dir;
	}
	robot() {};
};

map <char, pair<char, char>> m;
map <char, pair <int, int>> direction;

robot graph[101][101];
int A, B;

pair <int, int> BFS(robot& input, int index, char command, int count) {
	int ni = input.x;
	int nj = input.y;

	graph[input.x][input.y] = robot();

	for (int i = 0; i < count; i++) {
		if (command == 'L') {
			input.dir = m[input.dir].first;
		}
		else if (command == 'R') {
			input.dir = m[input.dir].second;
		}
		else if (command == 'F') {
			input.x = input.x + direction[input.dir].first;
			input.y = input.y + direction[input.dir].second;

			if (input.x <1 || input.y <1 || input.x > A || input.y >B) {
				return make_pair(index, -1);
			}
			if (graph[input.x][input.y].x != -1) {
				return make_pair(index, graph[input.x][input.y].index);
			}
		}
	}
	graph[input.x][input.y] = input;

	return make_pair(-1, -1);
}
int main() {

	cin >> A >> B;
	int N, M;
	cin >> N >> M;

	int x, y;
	char dir;

	vector<robot> v;

	for (int i = 0; i < N; i++) {
		scanf("%d %d %c", &x, &y, &dir);
		v.push_back(robot(x, y, i+1, dir));
		graph[x][y] = v[i];
	}

	int index;
	char command;
	int count;

	m['N'] = make_pair('W', 'E');
	m['W'] = make_pair('S', 'N');
	m['E'] = make_pair('N', 'S');
	m['S'] = make_pair('E', 'W');

	direction['N'] = make_pair(0, 1);
	direction['W'] = make_pair(-1, 0);
	direction['E'] = make_pair(1, 0);
	direction['S'] = make_pair(0, -1);

	for (int i = 0; i < M; i++) {
		scanf("%d %c %d", &index, &command, &count);
		pair <int ,int> result = BFS(v[index - 1], index, command, count);
		if (result.first != -1) {
			if (result.second == -1) {
				cout << "Robot " << index << " crashes into the wall";
			}
			else {
				cout << "Robot " << index << " crashes into robot " << result.second;
			}
			return 0;
		}

	}
	cout << "OK";
	//system("Pause");
}