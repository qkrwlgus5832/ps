#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;


set <int> s;

void all() {
	for (int i = 1; i <= 20; i++) {
		s.insert(i);
	}
}

int check(int x) {
	if (s.find(x) == s.end())
		return 0;
	return 1;
}
void toggle(int x) {
	if (check(x))
		s.erase(x);
	else
		s.insert(x);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int M;
	cin >> M;

	string command;
	int number;

	for (int i = 0; i < M; i++) {
		cin >> command;
		if (command == "all") {
			all();
			continue;
		}
		else if (command == "empty") {
			s.clear();
			continue;
		}
		cin >> number;
		if (command == "add") {
			s.insert(number);
		}
		else if (command == "remove") {
			s.erase(number);
		}
		else if (command == "check") {
			cout << check(number) << '\n'; // endl을 사용하면 버퍼를 flush하는 역할을 하므로 시간초과!
		}
		else if (command == "toggle") {
			toggle(number);
		}
		
	}

	//system("Pause");
}
