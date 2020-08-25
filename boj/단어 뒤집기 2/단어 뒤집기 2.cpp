#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

string S;
string result;

stack <char> st;
queue <char> q;

void getReversedWord() {
	while (st.size()) {
		result += st.top();
		st.pop();
	}
}

void getWord() {
	
	while (q.size()) {
		result += q.front();
		q.pop();
	}
	
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	getline(cin, S);

	bool tagFlag = false;

	for (char current : S) {

		if (current == ' ') {
			if (tagFlag == false) {
				getReversedWord();
			}
			else {
				getWord();
			}
			result += ' ';
		}
		else if (current == '<') {
			getReversedWord();
			result += '<';
			tagFlag = true;
		}
		else if (current == '>') {
			getWord();
			result += '>';
			tagFlag = false;
		}
		else if (tagFlag == false){
			st.push(current);
		}
		else {
			q.push(current);
		}

	}
	
	if (st.size() > 0) {
		getReversedWord();
	}
	else if (q.size() > 0) {
		getWord();
	}
	cout << result;
	//system("Pause");
}
