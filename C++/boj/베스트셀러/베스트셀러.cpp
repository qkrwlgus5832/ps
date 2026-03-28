#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;


map <string, int> m;
vector <pair <string, int>> v;

int main() {

	int N;
	cin >> N;
	string input;

	v.push_back({ "", -1 });

	for (int i = 0; i < N; i++) {
		cin >> input;
		if (m.count(input) == 0) {
			m[input] = m.size() + 1;
			v.push_back({ input, 1 });
		}
		else {
			v[m[input]].second++;
		}
		
	}

	sort(v.begin(), v.end(), [](const pair <string, int>& a, const pair <string, int>& b) {
		if (a.second == b.second) {
			return a.first < b.first;
		}
		return a.second > b.second;
	});

	cout << v[0].first;
	//system("Pause");
}