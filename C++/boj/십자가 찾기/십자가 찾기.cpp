#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>

using namespace std;

int N, M;
char graph[101][101];
bool check[101][101];

vector <pair <pair <int, int>, int>> result;

void crossCheck(int i, int j, int size) {
	int dir[4][2] = { {-1,0}, {1,0},{0,-1},{0,1} };


	for (int i1 = 0; i1 < 4; i1++) {
		int ni = i + dir[i1][0] * size;
		int nj = j + dir[i1][1] * size;
		
		check[ni][nj] = true;
	}

}

bool isCross(int i, int j, int size) {
	int dir[4][2] = { {-1,0}, {1,0},{0,-1},{0,1} };

	
	for (int i1 = 0; i1 < 4; i1++) {
		int ni = i + dir[i1][0] * size;
		int nj = j + dir[i1][1] * size;

		if (ni < 0 || nj < 0 || ni >= N || nj >= M)
			return false;
		if (graph[ni][nj] == '.') {
			return false;
		}
	}
	check[i][j] = true;
	crossCheck(i, j, size); // i 를 중심으로 check를 해준다.

	return true; // 십자가를 만들 수 있다.
}

void search(int N, int M) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (graph[i][j] == '*') {
				int size = 1;
				for (; size <= N; size++) {
					if (isCross(i, j, size) == false)
						break;
				}
				if (size - 1 >= 1)
					result.push_back({ {i,j}, size -1 });
			}
		}
	}
}

void checkIfAnswer() {
	for (int i = 0; i < N; i++) { // 십자가로 만들 수없는 map이라면 -1출력
		for (int j = 0; j < M; j++) {
			if (graph[i][j] == '*' && check[i][j] == false) {
				cout << -1;
				return;
			}
			
		}
	}
	cout << result.size() << endl; 
	for (pair <pair <int, int>, int> tmp : result){
		printf("%d %d %d\n", tmp.first.first + 1, tmp.first.second + 1, tmp.second);

	}

}

int main() {

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		scanf("%s", &graph[i]);
	}

	search(N, M);
	checkIfAnswer();

	//system("Pause");
}
