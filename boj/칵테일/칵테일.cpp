#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;


class ratio {
public:
	int a;
	int b;

	ratio(int a, int b) {
		this->a = a;
		this->b = b;
	}
	ratio() {};
};

class cocktail {
public:
	ratio ratio_;
	int index;

	cocktail(ratio ratio_, int index) {
		this->ratio_ = ratio_;
		this->index = index;
	}
};

vector <cocktail> graph[11];

ratio BFS(int x) {
	queue <cocktail> q;
	bool bfscheck[11] = { false, };

	for (int i = 0; i < graph[x].size(); i++) {
		q.push(graph[x][i]);
		bfscheck[graph[x][i].index] = true;
	}
	
	while (q.size()) {
		cocktail front = q.front();
		q.pop();

		if (front.index == 0) {
			return front.ratio_;
		}

		for (cocktail cocktail_ : graph[front.index]) {
			if (bfscheck[cocktail_.index] == false) {
				bfscheck[cocktail_.index] = true;
				ratio ratio_ = cocktail_.ratio_;

				ratio_.a *= front.ratio_.a;
				ratio_.b *= front.ratio_.b;

				q.push(cocktail(ratio_, cocktail_.index));
			}
		}
	}
}

int calculate(int maxValue, vector <ratio>& ratios) {
	for (;;) {
		bool flag = true;
		for (int j = 0; j < ratios.size(); j++) {
			if (maxValue % ratios[j].b != 0) {
				flag = false;
				break;
			}

		}
		if (flag)
			break;
		maxValue++;
	}
	return maxValue;
}

void getResult(vector <int>& tmp) {
	int minValue = tmp[0];
	for (int i = 0; i < tmp.size(); i++) {
		minValue = min(minValue, tmp[i]);
	}

	int maxDivisor = 1;
	
	for (int j = 2; j <= minValue; j++) {
		bool flag = true;
		for (int i = 0; i < tmp.size(); i++) {
			if (tmp[i] % j != 0) {
				flag = false;
				break;
			}
		}
		if (flag) {
			maxDivisor = j;
		}

	}
	for (int i = 0; i < tmp.size(); i++) {
		printf("%d ", tmp[i] / maxDivisor);
	}
}
int main() {
	int N;
	cin >> N;

	int a, b, p, q;

	for (int i = 0; i < N - 1; i++) {
		scanf("%d %d %d %d", &a, &b, &p, &q);
		ratio ratio_a = ratio(p, q);
		ratio ratio_b = ratio(q, p);
		
		graph[a].push_back(cocktail(ratio_a, b));
		graph[b].push_back(cocktail(ratio_b, a));

	}

	vector <ratio> ratios;

	int maxValue = 1;

	for (int i = 1; i < N; i++) {
		ratio ratio_ = BFS(i);
		ratios.push_back(ratio_);
		maxValue = max(maxValue, ratio_.b);
	}

	int standard = calculate(maxValue, ratios);

	vector <int> result;

	result.push_back(standard);
	for (ratio ratio_ : ratios) {
		result.push_back(ratio_.a * (standard / ratio_.b));
		
	}
	getResult(result);

	//system("Pause");
}
