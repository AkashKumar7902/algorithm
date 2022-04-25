#include <bits/stdc++.h>
using namespace std;
using namespace placeholders;
#define mem1(a) 		memset(a, -1, sizeof(a))
#define mem0(a)			memset(a, 0, sizeof(a))
#define pb push_back
#define pf push_front
#define ppb pop_back
#define ppf pop_front
#define fr first
#define sc second
#define ll long long
#define printst(st)		for(auto &i : st) cout << i << " "; cout << endl;
#define printvec(vec) for(auto elem : vec) cout << elem << " "; cout << endl;
#define printstack(st) while(!st.empty()) cout << st.top() << " ", st.pop(), cout <<endl;
#define MOD 1000000007

bool canPlaceCows(int stalls[], int n, int c, int min_sep) {

	// place the first cow in the first stall.
	int last_cow = stalls[0];
	int cow_cnt = 1;

	for (int i = 1; i < n; ++i) {
		if (stalls[i] - last_cow >= min_sep) {
			last_cow = stalls[i];
			cow_cnt++; // no of cows we have placed
			if (cow_cnt == c) {
				return true;
			}
		}
	}
	return false;
}

void solve() {

	int n; cin >> n;
	int cows; cin >> cows;
	int stalls[n] = {};
	for (int i = 0; i < n; ++i) {
		cin >> stalls[i];
	}
	sort(stalls, stalls + n);
	int s = 0;
	int e = stalls[n - 1] - stalls[0];
	int ans = 0;
	while (s <= e) {
		int mid = (s + e) / 2;
		bool cowsRakhPaye = canPlaceCows(stalls, n, cows, mid);
		if (cowsRakhPaye) {
			ans = mid;
			s = mid + 1;
		}
		else {
			e = mid - 1;
		}
	}
	cout << ans << endl;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int t; cin >> t;
	while (t--) {
		solve();
	}
}
