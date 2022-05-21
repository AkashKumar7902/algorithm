/*
      https://www.codingninjas.com/codestudio/problems/reverse-stack-using-recursion_631875?leftPanelTab=0
*/
#include <bits/stdc++.h>
using namespace std;

void insert(stack<int> &st, int temp) {
	if (st.size() == 0) {
		st.push(temp);
		return;
	}
	int temp2 = st.top();
	st.pop();
	insert(st, temp);
	st.push(temp2);
	return;
}


void print(stack<int> st);

void reverseStack(stack<int> &st) {
	if (st.size() == 0) {
		return;
	}
	int temp = st.top();
	st.pop();
	reverseStack(st);
	insert(st, temp);
}

void print(stack<int> st) {
	if (st.size() == 0) {
		return;
	}
	int temp = st.top();
	st.pop();
	print(st);
	cout << temp << " ";
	st.push(temp);
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n; cin >> n;
	int elem;
	stack<int> st;
	for (int i = 0; i < n; ++i) {
		cin >> elem;
		st.push(elem);
	}
	reverseStack(st);
	print(st);
}




