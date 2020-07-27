#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

bool check['F'*10 + '7'];
int dir[8][2] = { {2, -1}, {1,-2}, {2,1}, {1,2}, {-1,-2}, {-2, -1}, {-2,1},{-1,2} };


bool isCanGo(string& last, string& current) {
	if (last.size() == 2) {
		for (int i = 0; i < 8; i++) {
			char alpha = last[0] + dir[i][0];
			char number = last[1] + dir[i][1];
			if (alpha >= 'A' && alpha <= 'F' && number >= '1' && number <= '6') {
				if (current[0] == alpha && current[1] == number)
					return true;
			}
		}
	}
	return false;
}
bool isRange(string& current) {
	if (current.size() == 2 && current[0] >= 'A' && current[0] <= 'F' && current[1] >= '1' && current[1] <= '6')
		return true;
	return false;
}
int main() {
	string input;
	string last = "";
	string first;

	cin >> first;

	if (isRange(first))
		check[first[0] * 10 + first[1]] = true;
	last = first;

	for (int i = 1; i < 36; i++) {
		cin >> input;
		
		if (isRange(input)) {
			if (check[input[0] * 10 + input[1]] == false && isCanGo(last, input)) {
				check[input[0] * 10 + input[1]] = true;
				last = input;
				continue;
			}
		}
		
		cout << "Invalid";
		return 0;
	}
	if (isCanGo(last, first))
		cout << "Valid";

	else
		cout << "Invalid";
	//system("Pause");
}

