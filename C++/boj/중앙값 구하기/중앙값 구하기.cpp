#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;

void solution(vector <int> &result, vector <int> &input) {
	priority_queue <int> maxHeap;
	priority_queue <int, vector <int>, greater<int>> minHeap;
	int mid = input[0];
	result.push_back(input[0]);

	for (int i = 1; i < input.size(); i++) {
		if (input[i] > mid) 
			minHeap.push(input[i]);

		else
			maxHeap.push(input[i]);
		
		if (i % 2 == 0) {
			if (minHeap.size() < maxHeap.size()) {
				minHeap.push(mid);
				mid = maxHeap.top();
				maxHeap.pop();
			}
			else if (minHeap.size() > maxHeap.size()) {
				maxHeap.push(mid);
				mid = minHeap.top();
				minHeap.pop();
			}
			result.push_back(mid);
		}


	}
}
int main() {
	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		int m;
		scanf("%d", &m);
	
		vector <int> result;
		vector <int> input;
		
		input.resize(m);
		for (int i = 0; i < m; i++) {
			scanf("%d", &input[i]);
		}
		
		solution(result, input);
		
		printf("%d\n", result.size());
		for (int value : result) {
			printf("%d ", value);
		}
		printf("\n");
		
	}
	//system("Pause");
}
