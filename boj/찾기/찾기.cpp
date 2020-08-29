#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int check[1000001];

int main() {

	string T;
	string P;

	getline(cin, T);
	getline(cin, P);

	for (int i = P.size() - 1; i >= 1; i--) {
		if (P[i] == P[0]) {
			int count = 0;
			for (int j = 0, i1 = i; j < i &&  i1 < P.size(); j++, i1++) {
				if (P[j] == P[i1]) {
					count++;
				}
			}
			check[i] = count;
			break;
		}
	}

	int count = 0;
	int tmpcount = 0;

	vector <int> result;

	for (int i = 0; i < T.size();) {
		bool flag = true;
		for (int j = count; j < P.size(); j++) {

			if (T[i + j] == P[j]) {
				if (check[j] > 0) {
					tmpcount++;
				}

			}
			else {
				flag = false;
				if (tmpcount > 0) {
					count = tmpcount;
				}
				else {
					count = 0;
					i++;
				}
				break;
			}
			
		}
		if (flag) {
			result.push_back(i - count);
		}

	}

	system("Pause");
}

