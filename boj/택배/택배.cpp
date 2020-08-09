#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <memory.h>
#include <algorithm>

using namespace std;

class node {
public:
	int sender;
	int receiver;
	int count;

	node(int sender, int receiver, int count) {
		this->sender = sender;
		this->receiver = receiver;
		this->count = count;
	}
};

vector <node> v;

struct compare {
	bool operator()(node &a, node &b) {
		return a.receiver > b.receiver;

	}
};

priority_queue <node, vector <node>, compare> q;


int geMinAmount(int popAmount[2001], int sender, int receiver) {
	int amount = popAmount[sender];

	for (int i = sender; i < receiver; i++) {
		amount = min(amount, popAmount[i]);
	}
	return amount;
}


void set(int popAmount[2001], int sender, int receiver, int amount) {
	for (int i = sender; i < receiver; i++) {
		popAmount[i] -= amount;
	}

}
void init(int popAmount[2001], int N, int C) {
	for (int i = 1; i <= N; i++) {
		popAmount[i] = C;
	}
}

int main() {
	int N, C;
	cin >> N >> C;

	int M;
	cin >> M;

	int sender, receiver, count;

	for (int i = 0; i < M; i++) {
		scanf("%d %d %d", &sender, &receiver, &count);
		v.push_back(node(sender, receiver, count));
	}


	sort(v.begin(), v.end(), [](const node& a, const node& b) {
		if (a.receiver == b.receiver) {
			return a.sender < b.sender;
		}
		return a.receiver < b.receiver;
	});



	int sum = 0;
	int lastIndex = 1;
	int result = 0;
	int amount[2001] = { 0, };
	int popAmount[2001] = { 0, };

	init(popAmount, N, C);

	for (node& node_ : v) {
		int amount = geMinAmount(popAmount, node_.sender, node_.receiver);

		if (node_.count <= amount) {
			result += node_.count;
			set(popAmount, node_.sender, node_.receiver, node_.count);
		}
		else if (amount > 0) {
			result += amount;
			set(popAmount, node_.sender, node_.receiver, amount);
		}

	}

	cout << result;
	//system("Pause");
}
