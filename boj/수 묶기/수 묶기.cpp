#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

deque <int> plus_;
deque <int> minus_;

int N;

bool compare(int a, int b) { // 내림 차순으로 sort해주는 함수
	return a > b;
}

int getAnswerFromDeque(deque <int> &q) { // 두개씩 값을 묶어서 곱하고 더해준다.
	int value = 0;
	while (q.size()) {
		int first = q.front();
		q.pop_front();
		if (q.size()) {
			int second = q.front();
			q.pop_front();
			if (first * second > first + second) // 곱해주는 것보다 각각 더해주는값이 더 클 수 있으므로
				value += first * second;
			else
				value += first + second;
		}
		else {
			value += first;
		}
	}
	return value;
}
int main() {
	cin >> N;

	int tmp;
	for (int i = 0; i < N; i++) {
		scanf("%d", &tmp);
		if (tmp > 0) {
			plus_.push_back(tmp);
		}
		else if (tmp <= 0) {
			minus_.push_back(tmp);
		}
		//0값도 의미가 있다 0은 마이너스보다 크므로
	}
	sort(plus_.begin(), plus_.end(), compare); // 0보다 크다면 가장 큰값부터 묶어서 곱하는게 최대값
	sort(minus_.begin(), minus_.end());  // 0보다 작다면 가장 작은값부터 묶어서 곱하는게 최대값

	cout << getAnswerFromDeque(plus_) + getAnswerFromDeque(minus_); // plus minus값 각각 따로구한다.

	//system("Pause");
}
