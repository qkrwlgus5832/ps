#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;

int dir[9][2] = { {0,0}, {-1,0}, {-1, -1}, {0, -1}, {1, -1}, {1 ,0}, { 1,1 } , { 0 ,1},{ -1,1} };

int result = 0;

class fish {
public:
	int size;
	int direction;
	int x;
	int y;

	fish() {};
	fish(int size, int direction, int x, int y) {
		this->size = size;
		this->direction = direction;
		this->x = x;
		this->y = y;
	}
};

class shark {
public:
	int direction;
	int x;
	int y;

	shark(int direction, int x, int y) {
		this->direction = direction;
		this->x = x;
		this->y = y;
	}
};

fish graph[4][4];


vector<fish> getFishVector() {
	vector <fish> v;


	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			v.push_back(graph[i][j]);
		}

	}
	sort(v.begin(), v.end(), [](const fish& a, const fish& b) {
		return a.size < b.size;
	});
	return v;
}

int getIndex(vector <fish>& fishes, int size) {
	for (int i = 0; i < fishes.size(); i++) {
		if (fishes[i].size == size) {
			return i;
		}
	}
	return -1;
}
void fishMove(shark shark_, vector <fish>& fishes) {
	
	for (fish fish_: fishes) {
		if (fish_.size == -1)
			continue;

		bool flag = false;

		for (int i = fish_.direction; i < fish_.direction + 8; i= i % 8 + 1) {

			int ni = fish_.x + dir[i][0];
			int nj = fish_.y + dir[i][1];
			
			if (ni < 0 || nj < 0 || ni >= 4 || nj >= 4 || (ni == shark_.x && nj == shark_.y))
				continue;

			if (graph[ni][nj].size == -1) {
				graph[fish_.x][fish_.y] = fish(-1, -1, -1, -1);
				fish_.x = ni; fish_.y = nj; fish_.direction = i;
				graph[ni][nj] = fish_;
				break;
			} else{
				graph[fish_.x][fish_.y].direction = i;
				swap(graph[ni][nj].x, graph[fish_.x][fish_.y].x);
				swap(graph[ni][nj].y, graph[fish_.x][fish_.y].y);
				
				fishes[getIndex(fishes, graph[ni][nj].size)] = graph[ni][nj];
				swap(graph[ni][nj], graph[fish_.x][fish_.y]);
				break;
			}
	
		}

	}

}

void setGraph(fish copygraph[4][4]) {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			graph[i][j] = copygraph[i][j];

		}
	}
	
}
void dfs(shark shark_, int sum) {
	vector <fish> fishes = getFishVector(); // 원본 물고기 배열 정보
	fishMove(shark_, fishes);

	bool flag = false;
	
	fish copygraph[4][4];
	memcpy(copygraph, graph, sizeof(graph));

	for (int i = 1; i < 4; i++) {
		int ni = shark_.x + dir[shark_.direction][0] * i;
		int nj = shark_.y + dir[shark_.direction][1] * i;

		if (ni < 0 || nj < 0 || ni >= 4 || nj >= 4)
			break;

		fish tmp = graph[ni][nj];

		shark next = shark(tmp.direction, tmp.x, tmp.y);

		if (tmp.size != -1) {		
			sum += tmp.size;
			graph[ni][nj] = fish(-1, -1, -1, -1);
			dfs(next, sum);
			sum -= tmp.size; // 백트래킹
			graph[ni][nj] = tmp;
			setGraph(copygraph);
		}
	}
	
	result = max(result, sum);
	
}
int main() {
	int a, b;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			scanf("%d %d", &a, &b);
			graph[i][j] = fish(a, b, i, j);
		}
	}
	
	fish tmp = graph[0][0];

	graph[0][0] = fish(-1, -1, -1, -1);

	shark shark_ = shark(tmp.direction, tmp.x, tmp.y);
	
	dfs(shark_, tmp.size);

	cout << result;
	//system("Pause");
}
