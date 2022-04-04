


#include <bits/stdc++.h>
using namespace std;
using namespace placeholders;

#define ll long long

#define MOD 1000000009

void solve(stack<int> &s, int k) {
	if (k == 1) {
		s.pop();
		return;
	}
	int temp = s.top();
	s.pop();
	solve(s, k - 1);
	s.push(temp);
}


// mid = k = (st.size() + 1) / 2;

//    5   
//    4    
//    1 --> mid = (5 + 1) / 2 = 3;
//    2
//    3

stack<int> middel(stack<int> &s) {
	if (s.size() == 0)
		return s;
	int k = s.size() / 2 + 1;
	solve(s, k);
	return s;
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
	middel(v);
	while (!v.empty()) {
		cout << v.top() << endl;
		v.pop();
	}
}
