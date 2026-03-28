#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;


int N;
stack <pair <int,int>> st;

class building {
public:
	int L;
	int H;
	int R;

	building(int L, int H, int R) {
		this->L = L;
		this->H = H;
		this->R = R;
	}
};
vector <building> buildings;
vector <pair <int, int>> result;

int main() {
	cin >> N;

	int L, H, R;

	for (int i = 0; i < N; i++) {
		scanf("%d %d %d", &L, &H, &R);
		buildings.push_back(building(L, H, R));
	}
	sort(buildings.begin(), buildings.end());


	for (building current : buildings) {

	}
}