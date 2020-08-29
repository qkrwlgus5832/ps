#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>

using namespace std;


vector <char> v[11];
int N;

bool checkIfAnswer(int i, int depth, vector <int>& sum, vector <int>& tmpsum) {
	bool flag = true;

	for (int order = 0; order <= depth; order++) {
		if (sum[order] + i > 0 && v[order][depth - order] == '+')
			sum[order] += i;
		else if (sum[order] + i < 0 && v[order][depth - order] == '-')
			sum[order] += i;
		else if (sum[order] + i == 0 && v[order][depth - order] == '0')
			sum[order] += i;
		else
			flag = false;
	}
	if (flag) {
		return true;
	}

	copy(tmpsum.begin(), tmpsum.end(), sum.begin());
	return false;
}


void recursion(vector <int> result, vector <int> sum, int depth) {
	if (depth == N) {
		for (int i = 0; i < result.size(); i++) {
			cout << result[i] << " ";
		}
		
		exit(0);
	}
	vector <int> tmpsum;
	tmpsum.resize(N);
	copy(sum.begin(), sum.end(), tmpsum.begin());

	if (v[depth][0] == '+') {
		for (int i = 1; i <= 10; i++) {
			if (checkIfAnswer(i, depth, sum, tmpsum)) {
				result.push_back(i);
				recursion(result, sum, depth + 1);
				result.pop_back();
				copy(tmpsum.begin(), tmpsum.end(), sum.begin());
			}
		
		}
	}
	else if (v[depth][0] == '-') {
		for (int i = -10; i <= -1; i++) {
			if (checkIfAnswer(i, depth, sum, tmpsum)) {
				result.push_back(i);
				recursion(result, sum, depth + 1);
				result.pop_back();
				copy(tmpsum.begin(), tmpsum.end(), sum.begin());
			}
		}
	}
	else {
		if (checkIfAnswer(0, depth, sum, tmpsum)) {
			result.push_back(0);
			recursion(result, sum, depth + 1);
			result.pop_back();
		}
	}

}

int main() {
	
	cin >> N;

	char ch;

	for (int i = N, i1= 0; i >=1; i--, i1++) {
		for (int j = 0; j < i; j++) {
			cin >> ch;
			v[i1].push_back(ch);
		}
	}

	vector <int> result;
	result.resize(N);
	recursion({}, result, 0);

	//system("Pause");
}
