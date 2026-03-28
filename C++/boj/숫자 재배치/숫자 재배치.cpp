#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int A, B;

string input;

int result = -1;

bool isAnswer(string &v) {
	if (v[0] == '0')
		return false;
	int value = stoi(v);
	if (value > B)
		return false;
	return true;

}
void combination(string &v, bool check[10]) {
	if (v.size() == input.size()) {
		if (isAnswer(v))
			result = max(result, stoi(v));
	}
	for (int i = 0; i < input.size(); i++) {
		if (check[i] == false) {
			check[i] = true;
			v.push_back(input[i]);
			combination(v, check);
			check[i] = false;
			v.pop_back();
		}
	}
}

int main() {

	cin >> A >> B;

	string v = "";
	input = to_string(A);

	bool check[10] = { false, };
	combination(v, check);
	cout << result;
	//system("Pause");
}
