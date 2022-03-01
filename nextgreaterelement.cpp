/*****************************

      For explanation, 
      https://www.youtube.com/watch?v=T-E3hWEPWWU&t=999s
      
*****************************/

#include <bits/stdc++.h>
using namespace std;
using namespace placeholders;
#define ll long long
const ll mod = 1e9 + 7;

vector<int> NGE(vector<int> v) {
	vector<int> nge(v.size());
	stack<int> st;
	for (int i = 0; i < v.size(); ++i) {
		while (!st.empty() && v[st.top()] < v[i]) {
			nge[st.top()] = i;
			st.pop();
		}
		st.push(i);
	}
	while (!st.empty()) {
		nge[st.top()] = -1;
		st.pop();
	}
	return nge;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n; cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; ++i) {
		cin >> v[i];
	}
	vector<int> nge = NGE(v);
	for (int i = 0; i < n; ++i) {
		cout << v[i] << " " << (nge[i] == -1 ? -1 : v[nge[i]]) << endl;
	}
}
