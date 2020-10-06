#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

unordered_map <int, unordered_map <int, bool>> m;

int main() {
	int N;
	cin >> N;

	int a, b;
	for (int i = 0; i < N - 1; i++) {
		scanf("%d %d", &a, &b);
		m[a][b] = 1;
		m[b][a] = 1;
	}

	int input;
	
	int previous = 0;

	bool result = true;
	int count = 0;

	vector <int> inputs;
	queue <int> q;

	for (int i = 0; i < N; i++) {
		scanf("%d", &input);
		
		if (i == 0) {
			if (input == 1)
				q.push(input);
			else
				result = false;
			continue;
		}
		if (q.size() && m[q.front()][input] == 1) {
			q.push(input);
		}
		else {
			if (q.size() >= 2) {
				q.pop();
				if (m[q.front()][input] == 1)
					continue;
			}
			result = false;
		}
	}

	
	cout << result;
	//system("Pause");
}
