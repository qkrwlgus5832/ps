#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

int N, S, M;
vector <int> v;
bool check[101][1001];
int result = -1;

void dfs(int index, int volume) {
	if (index == N) {
		result = max(result, volume);
		return;
	}
	if (volume + v[index] <= M && check[index][volume + v[index]] == false){
		check[index][volume + v[index]] = true;
		dfs(index + 1, volume + v[index]);
	}
	if (volume - v[index] >= 0 && check[index][volume - v[index]] == false) {
		check[index][volume - v[index]] = true;
		dfs(index + 1, volume - v[index]);
	}

}

int main() {
	cin >> N >> S >> M;

	v.resize(N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &v[i]);
	}
	dfs(0, S);
	cout << result;
	
	//system("Pause");
}
