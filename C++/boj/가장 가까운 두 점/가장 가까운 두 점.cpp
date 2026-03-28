#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <limits.h>
using namespace std;

int n;

int minDistance = INT_MAX;

class point {
public:
	int x;
	int y;

	point(int x, int y) {
		this->x = x;
		this->y = y;

	}
};
vector <point> v;

int getDistance(point &a, point &b) {
	return pow(a.x - b.x, 2) + pow(a.y - b.y, 2);
}

bool compare(point &a, point &b) {
	return a.y < b.y;
}
void divideAndConquer_x(pair <int, int> xLange) {
	if (xLange.first == xLange.second)
		return;
	if (xLange.first + 1 == xLange.second) {
		minDistance = min(minDistance, getDistance(v[xLange.first], v[xLange.second]));
		return;
	}

	int standardIndex = (xLange.second + xLange.first) / 2;  // 가운데를 구함

	divideAndConquer_x({ xLange.first, standardIndex - 1 });
	divideAndConquer_x({ standardIndex + 1, xLange.second });

	vector <point> candidates;

	candidates.push_back(v[standardIndex]);

	for (int i = 1; standardIndex + i <= xLange.second; i++) {
		if (pow(v[standardIndex + i].x - v[standardIndex].x, 2) < minDistance) {
			int dist = getDistance(v[standardIndex + i], v[standardIndex]);
			minDistance = min(minDistance, dist);
			candidates.push_back(v[standardIndex + i]);
		}
		else
			break;
	}
	for (int i = 1; standardIndex - i >= xLange.first; i++) {
		if (pow(v[standardIndex].x - v[standardIndex - i].x, 2) < minDistance) {
			int dist = getDistance(v[standardIndex - i], v[standardIndex]);
			minDistance = min(minDistance, dist);
			candidates.push_back(v[standardIndex - i]);
		}
		else
			break;
	}
	sort(candidates.begin(), candidates.end(), compare);

	for (int i = 0; i < candidates.size(); i++) {
		for (int j = i + 1; j < candidates.size(); j++) {
			if (pow(candidates[j].y - candidates[i].y, 2) < minDistance) {
				int dist = getDistance(candidates[i], candidates[j]);
				minDistance = min(minDistance, dist);
			}
			else
				break;
		}
	}

}
int main() {
	cin >> n;
	int x, y;

	for (int i = 0; i < n; i++) {
		scanf("%d %d", &x, &y);
		v.push_back(point(x, y));
	}
	sort(v.begin(), v.end(), [](const point&a, const point&b) {
		return a.x < b.x;
	}); // x축을 중심으로 한번 정렬


	divideAndConquer_x({ 0, n - 1 });
	cout << minDistance;
	//system("Pause");
}