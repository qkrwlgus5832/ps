#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;


int N;
vector <int> v;


int main() {
	cin >> N;
	v.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> v[i];
	}

	sort(v.begin(), v.end());

	int last = 0;
	
	
	for (int i = 0; i < N; i++) {
		if (v[i] > last + 1) {
				break;
		}
		last += v[i];
	}
	
	cout << last + 1;

	//system("Pause");
}
