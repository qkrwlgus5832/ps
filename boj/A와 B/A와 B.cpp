#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <queue>

using namespace std;

string S, input;
deque <char> T; // pop_front, pop_back�� ���� �ϱ� ���ؼ� deque���� ���� 


int main() {
	cin >> S;
	cin >> input;
	
	int diff = input.size() - S.size(); 

	for (int i = 0; i < input.size(); i++) {
		T.push_back(input[i]);
	}

	bool reserve = false;

	for (int i = 0; i < diff; i++) { // T�� S�� ���̸�ŭ �ݺ�
		if (!reserve) {
			if (T.back() == 'A') {
				T.pop_back();
			}
			else if (T.back() == 'B') {
				T.pop_back();
				reserve = !reserve;
			}
			else
				break;
		}
		else {
			if (T.front() == 'A') {
				T.pop_front();
			}
			else if (T.front() == 'B') {
				T.pop_front();
				reserve = !reserve;
			}
			else
				break;
		}
	
	}

	if (T.size() != S.size()) {
		cout << 0;
		return 0;
	}
	//T�� S�� ������ Ȯ��
	if (reserve) { // �Ųٷ� Ȯ��
		for (int i = 0; i < S.size(); i++) {
			if (T[T.size() - 1 - i] != S[i]) {
				cout << 0;
				return 0;
			}
		}
		cout << 1;
	}
	else { 
		for (int i = 0; i < S.size(); i++) {
			if (T[i] != S[i]) {
				cout << 0;
				return 0;
			}
		}
		cout << 1;
	}
	//system("Pause");
}