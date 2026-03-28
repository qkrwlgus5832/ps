#include <iostream>
#include <map>


using namespace std;

int result = 0;
map <pair <int, int>, int> m;
int recursion(int plus, int mul, int value) {
	if (mul >= 40)
		return 0;
	if (value == 1) {
		if (plus == 0)
			result++;
		return 1;
	}
	if (plus >= 2 && value % 3 == 0) {
		if (m.count({ plus, value }) == 0) {
			m[{plus, value}] += recursion(plus - 2, mul + 1, value / 3);
			m[{plus, value}] += recursion(plus + 1, mul, value - 1);
		}
	}
	else
		m[{plus, value}] += recursion(plus + 1, mul, value - 1);

	return m[{plus, value}];
}
int solution(int n) {
	int answer = 0;
	recursion(0, 0, n);
	return result;
}

int main() {
	m.clear();
	cout << solution(41);
	system("Pause");
}