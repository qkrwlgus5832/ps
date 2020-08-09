#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>

using namespace std;

int N, K;

deque <int> v[21];
long long result = 0;
queue <int> q[21];



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	cin >> N >> K;

	string input;
	for (int i = 0; i < N; i++) {
		cin >> input;
		v[input.size()].push_back(i + 1);
	}



	for (int i = 1; i <= 20; i++) {

		for (int j = 0; j < v[i].size(); j++) {
			if (!(q[i].size() == 0 || v[i][j] - q[i].front() <= K)) {
				while (q[i].size()) {
					if (v[i][j] - q[i].front() > K) {
						q[i].pop();
					}
					else
						break;
				}
			}
			result += q[i].size();
			q[i].push(v[i][j]);

		}
	}
	cout << result;
	//system("Pause");
}