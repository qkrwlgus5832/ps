#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <stdio.h>

using namespace std;

vector <int> v[100001];
vector <int> inorderInput;
vector <int> postorderInput;
vector <int> preorderOutput;

int makeTree(int inorderStart, int inorderEnd, int postorderStart, int postorderEnd) {
	if (inorderEnd == inorderStart) {
		return inorderInput[inorderStart];
	}
	int root = postorderInput[postorderEnd];
	int leftroot = -1;
	int rightroot = -1;
	for (int i = inorderStart; i <= inorderEnd; i++) {
		if (inorderInput[i] == root) {
			int leftcount = i - inorderStart;
			int rightcount = inorderEnd - i;

			if (leftcount >= 1)
				leftroot = makeTree(inorderStart, i - 1, postorderStart, postorderStart + leftcount - 1);

			if (rightcount >= 1)
				rightroot = makeTree(i + 1, inorderEnd, postorderStart + leftcount, postorderStart + leftcount + rightcount - 1);

			break;
		}
	}

	v[root].push_back(leftroot);
	v[root].push_back(rightroot);
	return root;
}

void preOrderSearch(int root) {
	if (root == -1) {
		return;
	}
	preorderOutput.push_back(root);

	if (v[root].size() > 0) {
		preOrderSearch(v[root][0]);
		preOrderSearch(v[root][1]);
	}

}
int main() {
	int n;
	cin >> n;
	int tmp;

	for (int i = 0; i < n; i++) {
		scanf("%d", &tmp);
		inorderInput.push_back(tmp);
	}
	for (int i = 0; i < n; i++) {
		scanf("%d", &tmp);
		postorderInput.push_back(tmp);
	}
	int root = makeTree(0, n - 1, 0, n - 1);
	preOrderSearch(root);

	for (int i = 0; i < preorderOutput.size(); i++) {
		printf("%d ", preorderOutput[i]);
	}
	//system("Pause");

}
