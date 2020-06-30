#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector <char> operator_;
vector <int>  operand_;

bool check[51];

int checkWhilePlus(int index) { // 플러스일때까지 더해주는 함수
	int value = operand_[index];

	for (int i = index; i < operator_.size(); i++) {
		if (operator_[i] == '+') {
			value += operand_[i + 1];
			check[i] = true;
		}
		else
			return value;
	}
	return value;
}
int main() {
	string input;
	cin >> input;

	int value = 0;
	for (int i = 0; i < input.size(); i++) {
		
		if (input[i] >= '0' && input[i] <= '9') {
			value = value * 10 + (input[i] - '0');
		}
		else {
			operand_.push_back(value);
			operator_.push_back(input[i]);
			value = 0;
		}
	}
	operand_.push_back(value);
	value = operand_[0];

	for (int i = 0; i < operator_.size(); i++) {
		if (check[i] == true) {
			continue;
		}
		if (operator_[i] == '+') { // +일떄는 그냥 더해준다.
			value += operand_[i + 1];
		}
		else { // 마이너스 연산자라면 플러스값일때까지 더해서 그값을 빼준다 => 최소값을 구하기 위해
			int tmp = checkWhilePlus(i + 1);
			value -= tmp;
		}
	}
	cout << value;
	//system("Pause");
}
