#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;

int N, K;
bool angle[361];
vector <int> v;

void BFS() {
	queue <int> q;
	q.push(0);

	while (q.size()) {
		int front = q.front();
		q.pop();

		for (int i = 0; i < v.size(); i++) {
			int n = front + v[i];

			if (n > 360) {
				n = n - 360;
			}

			if (angle[n] == false) {
				angle[n] = true;
				q.push(n);
			}

			n = front - v[i];

			if (n < 0) {
				n = 360 - abs(n);
			}

			if (angle[n] == false) {
				angle[n] = true;
				q.push(n);
			}

		}

	}
}

int main() {
	cin >> N >> K;
	
	int input;
	for (int i = 0; i < N; i++) {
		scanf("%d", &input);
		v.push_back(input);
	}

	BFS();

	for (int i = 0; i < K; i++) {
		scanf("%d", &input);
		if (angle[input]) {
			printf("YES\n");
		}
		else {
			printf("NO\n");
		}
	}
	
	//system("Pause");
}
