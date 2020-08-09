#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>

using namespace std;

int check[500001];


void BFS(int N) {
	queue <int> q;
	q.push(N);

	check[N] = 1;

	int length = 1;
	
	while (q.size()) {
		int s = q.size();

		for (int qs = 0; qs < s; qs++) {
			int front = q.front();
			q.pop();


			if (front + 1 <= 500000 && check[front + 1] == false) {
				check[front + 1] = length + 1;
				q.push(front + 1);
			}
			if (front - 1 >= 0 && check[front - 1] == false) {
				check[front - 1] = length + 1;
				q.push(front - 1);
			}
			if (2 * front <= 500000 && check[2 * front] == false) {
				check[2 * front] = length + 1;
				q.push(2 * front);
			}

			
		}
		length++;
	}

}
int main() {
	int N, K;

	cin >> N >> K;

	BFS(N);
	
	int count  = 0;
	bool flag = false;
	for (int i = K; i <= 500000; i += count) {
		if (check[i]  -1 <= count && abs(count - check[i]) % 2 == 1) {
			flag = true;
			break;
		}
		count++;
	}
	if (flag)
		cout << count;
	else
		cout << -1;

	system("Pause");
}

