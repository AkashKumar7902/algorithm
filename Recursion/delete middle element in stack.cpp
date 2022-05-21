#include <bits/stdc++.h>
using namespace std;

void middel(stack<int> &st, int n) {
	if (n == 1) {
		st.pop();
		return;
	}
	int temp = st.top();
	st.pop();
	middel(st, n - 1);
	st.push(temp);
	return;
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
	middel(st, st.size() / 2 + 1);
	print(st);
}




