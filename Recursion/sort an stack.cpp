#include <bits/stdc++.h>
using namespace std;
using namespace placeholders;

#define ll long long

#define MOD 1000000009

void insert(stack<int> &st, int temp) {
	if (st.size() == 0 or st.top() <= temp) {
		st.push(temp);
		return;
	}
	int val = st.top();
	st.pop();
	insert(st, temp);
	st.push(val);
}

void sorting(stack<int> &st) {
	if (st.size() == 1) {
		return;
	}
	int temp = st.top();
	st.pop();
	sorting(st);
	insert(st, temp);
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	stack<int> v;
	int n; cin >> n;
	for (int i = 0; i < n; ++i) {
		int num; cin >> num;
		v.push(num);
	}
	sorting(v);
	while (!v.empty()) {
		cout << v.top() << endl;
		v.pop();
	}
}
