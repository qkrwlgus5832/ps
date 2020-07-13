#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>

using namespace std;


int N, M;

vector <int> lessons;

bool isAnswer(int x) {
	int tmp = 0;
	int count = 1;
	for (int lesson : lessons) {
		if (tmp + lesson > x) {
			if (lesson > x)
				return false;
			tmp = lesson;
			count++;
		}
		else
			tmp += lesson;
	}
	if (count > M)
		return false;
	return true;
}

int binary_search(int start, int end) {
	if (start == end)
		return start;
	else if (start + 1 == end) {
		if (isAnswer(start))
			return start;
		return end;
	}
	if (isAnswer((start + end) / 2)) {
		return binary_search(start, (start + end) / 2);
	}
	else {
		return binary_search((start + end) / 2 + 1, end);
	}

}
int main() {
	cin >> N >> M;

	lessons.resize(N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &lessons[i]);
	}
	cout << binary_search(0, 10000 * 100000);
	
	//system("Pause");

}
