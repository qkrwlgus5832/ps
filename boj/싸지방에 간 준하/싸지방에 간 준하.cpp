#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

set <int> computer;
map <int, int> check;
int result[100001];

class person{
public:
	char startOrEnd;
	int index;
	int time;

	person(char startOrEnd, int index, int time) {
		this->startOrEnd = startOrEnd;
		this->index = index;
		this->time = time;
	}
};

vector <person> v;

int main() {
	int N;
	cin >> N;

	int P, Q;
	
	for (int i = 0; i < N; i++) {
		scanf("%d %d", &P, &Q);
		v.push_back(person('s', i, P));
		v.push_back(person('e', i, Q));
	}

	sort(v.begin(), v.end(), [](const person& a, const person& b) {
		return a.time < b.time;
	});

	int computerCount = 0;

	for (person current : v) {
		if (current.startOrEnd == 's') {
			if (computer.size() > 0) {
				check[current.index] = *computer.begin();
				result[*computer.begin()]++;
				computer.erase(computer.begin());
			}
			else {
				check[current.index] = computerCount;
				result[computerCount]++;
				computerCount++;
				
			}
		}
		else {
			computer.insert(check[current.index]);
		}
	}
	cout << computerCount << endl;
	for (int i = 0; i < computerCount; i++) {
		printf("%d ", result[i]);
	}
	//system("Pause");
}
