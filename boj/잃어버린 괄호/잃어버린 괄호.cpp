#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector <char> operator_;
vector <int>  operand_;

bool check[51];

int checkWhilePlus(int index) { // �÷����϶����� �����ִ� �Լ�
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
		if (operator_[i] == '+') { // +�ϋ��� �׳� �����ش�.
			value += operand_[i + 1];
		}
		else { // ���̳ʽ� �����ڶ�� �÷������϶����� ���ؼ� �װ��� ���ش� => �ּҰ��� ���ϱ� ����
			int tmp = checkWhilePlus(i + 1);
			value -= tmp;
		}
	}
	cout << value;
	//system("Pause");
}
