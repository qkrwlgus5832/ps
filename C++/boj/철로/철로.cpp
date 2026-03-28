#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;


vector <pair <int, int>> points;

int main() {
	int n;
	int d;
	cin >> n;

	int hi, oi;

	for (int i = 0; i < n; i++) {
		scanf("%d %d", &hi, &oi);
		if (hi > oi)
			swap(hi, oi);
		points.push_back({ hi, oi });
	}
	cin >> d;

	sort(points.begin(), points.end(), [](const pair <int, int>& a, const pair <int, int>& b) {
		return a.second < b.second;
	});


	priority_queue <int, vector <int>, greater<int>> q;

	int result = 0;

	for (pair <int, int> point : points) {
		while (q.size()) {
			if (q.top() < point.second - d) {
				q.pop();
			}
			else
				break;
		}
		if (point.second - point.first <= d)
			q.push(point.first);
		result = max(result, (int)q.size());
	}
	cout << result;
	//system("Pause");
}
