#include <bits/stdc++.h>
using namespace std;
using namespace placeholders;

#define ll long long

#define MOD 1000000009

int stringtoint(string s, int n) {
	if (n == 0) {
		return 0;
	}
	int digit = s[n - 1] - '0';
	int small_ans = stringtoint(s, n - 1);
	return small_ans * 10 + digit;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	string s; cin >> s;
	int n = s.size();
	int c = stringtoint(s, n);
	cout << c << endl;
}
