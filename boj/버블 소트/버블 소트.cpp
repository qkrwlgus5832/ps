#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
using namespace std;


long long swapp;
int N1[500001];

queue <int> merge(queue <int> v1, queue <int> v2) { // 정렬된 배열들을 합치면서 swap 횟수를 세준다.
	queue <int> v;
	while (1) {
		if (v1.size() == 0 && v2.size() == 0)
			break;
		if (v1.size() >= 1 && v2.size() >= 1) {
			if (v1.front() <= v2.front()) { // swap할 필요 없는 경우
				v.push(v1.front());
				v1.pop();

			}
			else { // swap 해야하는 경우
				v.push(v2.front());
				v2.pop();
				swapp = swapp + v1.size();
			}
		}
		else if (v1.size() >= 1) {
			v.push(v1.front());
			v1.pop();

		}
		else if (v2.size() >= 1) {
			v.push(v2.front());
			v2.pop();

		}
	}

	return v;
}

queue <int> mergesort(int i, int j) { // 쪼개면서 분할 정복한다.
	if (i == j) {
		queue <int> tmp;
		tmp.push(N1[i]);
		return tmp;
	}

	else {
		return merge(mergesort(i, (i + j) / 2), mergesort((i + j) / 2 + 1, j));
	}


}

int N;
int main() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		scanf("%d", &N1[i]);

	}



	queue <int> result = mergesort(0, N - 1);

	cout << swapp;

}