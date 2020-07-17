#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

vector <long long> v;
vector <long long> graph[101];
int N;
map <long long, int> check; // ���� ũ�Ⱑ 100���̰� ������ 10^18�����̹Ƿ� 
map <long long, int> compress; // map�� �̿��ؼ� ��ǥ ����!

long long searchStart() { // ���������� 0�ΰ� ���� �����Ѵ�.
	for (auto tmp : check) {
		if (tmp.second == 1) {
			return tmp.first;
		}
	}
}

void init() { 
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (i == j)
				continue;
			int compressI = compress[v[i]];
			if (v[i] % 3 == 0 && v[i] / 3 == v[j]) {
				graph[compressI].push_back(v[j]);
				check[v[j]]++;
			}
			if (v[i] * 2 == v[j]) {
				graph[compressI].push_back(v[j]);
				check[v[j]]++;
			}
			
		}
	}
}

void DFS(long long current, vector <long long>& v) {
	if (v.size() == N) {
		return;
	}
	int compressCurrent = compress[current];

	if (graph[compressCurrent].size() == 1) {
		v.push_back(graph[compressCurrent][0]);
		DFS(graph[compressCurrent][0], v);
	}
	if (graph[compressCurrent].size() == 2) {
		if (check[graph[compressCurrent][0]] < check[graph[compressCurrent][1]]) { // ���� ������ ���� ���� �켱���� ���ش�.
			v.push_back(graph[compressCurrent][0]);
			DFS(graph[compressCurrent][0], v);
		}
		else {
			v.push_back(graph[compressCurrent][1]);
			DFS(graph[compressCurrent][1], v);
		}
	}
}
int main() {

	cin >> N;

	v.resize(N);

	for (int i = 0; i < N; i++) {
		scanf("%lld", &v[i]);
		check[v[i]] = 1;
	}

	sort(v.begin(), v.end()); 

	for (int i = 0; i < v.size(); i++) { 
		compress[v[i]] = i;
	}

	init();

	long long start = searchStart();

	vector <long long> result;
	result.push_back(start);
	DFS(start, result);

	for (int i = 0; i < result.size(); i++) {
		printf("%lld ", result[i]);
	}
	//system("Pause");
}
