#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <map>
#include <string>
using namespace std;

map <int, int> m;
int s, t;

void queuepush(queue <pair <long long, string>> &q, int value, string frontChar, char oper) {
	if (value <= t && m.count(value) == 0) {
		m[value] = 1;
		q.push({ value, frontChar + oper });
	}
}

bool BFS(int value) {
	queue <pair <long long, string>> q;
	m[value] = 1;
	string v = "";

	q.push({ value, v });

	while (q.size()) {
		pair <long long, string> front = q.front();
		if (front.first == t) {
			cout << front.second;
			return true;
		}
		q.pop();
		queuepush(q, front.first * front.first, front.second, '*');
		queuepush(q, front.first + front.first, front.second, '+');
		queuepush(q, front.first - front.first, front.second, '-');

		if (front.first != 0)
			queuepush(q, front.first / front.first, front.second, '/');

	}


	return false;
}
int main() {

	cin >> s >> t;

	queue <pair <long long, string>> q;
	queuepush(q, 0000000000000, "", '+');
	if (s == t) {
		cout << 0;
	}
	else if (BFS(s) == false) {
		cout << -1;
	}
	//system("Pause");

}