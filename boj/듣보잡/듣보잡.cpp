#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	int M;

	cin >> N >> M;

	string input;

	map <string, bool> m;

	for (int i = 0; i < N; i++) {
		cin >> input;
		m[input] = true;
	}

	vector <string> result;

	for (int i = 0; i < M; i++) {
		cin >> input;

		if (m[input] == true) {
			result.push_back(input);
		}
	}

	cout << result.size() << endl;
	sort(result.begin(), result.end());
	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << '\n';
	}
	//system("Pause");
}
