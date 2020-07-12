#include <string>
#include <vector>
#include <unordered_map>
#include <set>
#include <limits.h>

using namespace std;

unordered_map <string, int> m;
set <string> kinds;


void moveLeft(vector <string> &gems, int &left, int &right) {
	for (int i = left; i < right; i++) {
		if (m[gems[i]] > 1) {
			m[gems[i]]--;
			left++;
		}
		else
			break;
	}
}

void moveRight(vector <string> &gems, int &right) {
	m[gems[++right]]++;

}
vector<int> solution(vector<string> gems) {
	vector<int> answer;

	int start = 0;
	int end = 0;
	int tmp = INT_MAX;

	m[gems[0]] = 1;

	for (string gem : gems) {
		kinds.insert(gem);
	}

	while (1) {
		if (m.size() == kinds.size()) {
			if (tmp > end - start + 1) {
				answer = { start + 1, end + 1 };
				tmp = end - start + 1;
			}
		}
		if (start == gems.size() - 1 || end == gems.size() - 1)
			return answer;
		moveLeft(gems, start, end);
		if (m.size() == kinds.size()) {
			if (tmp > end - start + 1) {
				answer = { start + 1, end + 1 };
				tmp = end - start + 1;
			}
		}
		moveRight(gems, end);
	}


	return { 1, (int)gems.size() };
}


int main() {
	solution({ "DIA", "RUBY", "RUBY", "EME", "EME", "DIA", "RUBY", "EME" });
}