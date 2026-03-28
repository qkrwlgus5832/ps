#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

unordered_map <int, unordered_map <int, unordered_map <int, bool>>> m;

struct stone {
	int A;
	int B;
	int C;
};

void checkCases(int A, int B, int C) {
	m[A][B][C] = m[A][C][B] = m[B][A][C] = m[B][C][A] = m[C][A][B] = m[C][B][A]= true;
}
void queuepush(int X, int Y, int Z, queue <stone>& q) {
	if (X > Y)
		swap(X, Y);

	if (2 * X < 1500 && m[2 * X][Y - X][Z] == false) {
		checkCases(2 * X, Y - X, Z);
		q.push({ 2 * X, Y - X, Z });
	}
}
bool BFS(int A, int B, int C) {

	queue <stone> q;
	q.push({ A, B, C });
	checkCases(A, B, C);

	while (q.size()) {
		stone front = q.front();
		if (front.A == front.B && front.B == front.C)
			return true;
		q.pop();

		if (front.A != front.B) {
			queuepush(front.A, front.B, front.C, q);
		}
		if (front.B != front.C) {
			queuepush(front.B, front.C, front.A, q);
		}
		if (front.C != front.A) {
			queuepush(front.C, front.A, front.B, q);
		}
	}
	return false;
}
int main() {

	int A, B, C;
	cin >> A >> B >> C;
	cout << BFS(A, B, C);
	//system("Pause");

}