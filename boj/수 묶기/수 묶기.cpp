#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

deque <int> plus_;
deque <int> minus_;

int N;

bool compare(int a, int b) { // ���� �������� sort���ִ� �Լ�
	return a > b;
}

int getAnswerFromDeque(deque <int> &q) { // �ΰ��� ���� ��� ���ϰ� �����ش�.
	int value = 0;
	while (q.size()) {
		int first = q.front();
		q.pop_front();
		if (q.size()) {
			int second = q.front();
			q.pop_front();
			if (first * second > first + second) // �����ִ� �ͺ��� ���� �����ִ°��� �� Ŭ �� �����Ƿ�
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
		//0���� �ǹ̰� �ִ� 0�� ���̳ʽ����� ũ�Ƿ�
	}
	sort(plus_.begin(), plus_.end(), compare); // 0���� ũ�ٸ� ���� ū������ ��� ���ϴ°� �ִ밪
	sort(minus_.begin(), minus_.end());  // 0���� �۴ٸ� ���� ���������� ��� ���ϴ°� �ִ밪

	cout << getAnswerFromDeque(plus_) + getAnswerFromDeque(minus_); // plus minus�� ���� ���α��Ѵ�.

	//system("Pause");
}
