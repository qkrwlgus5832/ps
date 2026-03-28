#include <bits/stdc++.h>

using namespace std;


vector <int> process;


int getWorkCount(int time, vector <int> &cores) {
	int count = 0;
	for (int i = 0; i < cores.size(); i++) {
		count += time / cores[i];
		if (count > 50000)
			return 50001;
	}
	return count;
}
int binary_search_(int start, int end, int n, vector <int> &cores) {
	if (start == end)
		return start;

	if (start + 1 == end) {
		if (getWorkCount(start, cores) >= n)
			return start;
		return end;
	}

	if (getWorkCount((start + end) / 2, cores) < n) {
		binary_search_((start + end) / 2 + 1, end, n, cores);
	}
	else {
		binary_search_(start, (start + end) / 2, n, cores);
	}
}

int solution(int n, vector<int> cores) {


	if (cores.size() >= n)
		return n;

	int time = binary_search_(0, 50000 * 10000, n - cores.size(), cores);


	vector <int> coreCount;


	for (int i = 0; i < cores.size(); i++) {
		int count1 = (time - 1) / cores[i];
		int count2 = time / cores[i];

		coreCount.push_back(count2 - count1);
	}

	int count = getWorkCount(time - 1, cores) + cores.size();

	for (int i = 0; i < coreCount.size(); i++) {
		count += coreCount[i];
		if (count == n)
			return i + 1;
	}

	return -1;
}

int main() {
	solution(6, { 1,2,3 });
}