

#include <bits/stdc++.h>
using namespace std;
using namespace placeholders;

#define ll long long

#define MOD 1000000009

void insert(vector<int> &v, int temp) {
	if (v.size() == 0 or v[v.size() - 1] <= temp) {
		v.push_back(temp);
		return;
	}
	int val = v.back();
	v.pop_back();
	insert(v, temp);
	v.push_back(val);
}

void sorting(vector<int> &v) {
	if (v.size() == 1) {
		return;
	}
	int temp = v.back();
	v.pop_back();
	sorting(v);
	insert(v, temp);
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	vector<int> v;
	int n; cin >> n;
	for (int i = 0; i < n; ++i) {
		int num; cin >> num;
		v.push_back(num);
	}
	sorting(v);
	for (auto &i : v) {
		cout << i << " ";
	}
}
