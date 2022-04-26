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

bool func(vector<int> &v, int mid, int p) {
	int t_parathas = 0;
	for (int i = 0; i < v.size(); ++i) {
		int time = 0;
		int parathas = 0;
		int j = 1;
		while (parathas <= p && time <= mid) {
			time += v[i] * (j++);
			if (time <= mid)
				parathas++;
		}
		t_parathas += parathas;
	}
	if (t_parathas >= p) {
		return true;
	}
	return false;
}

void solve() {
	int p; cin >> p;
	int l; cin >> l;
	vector<int> v(l);
	for (int i = 0; i < l; ++i) {
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	int i = 0;
	int j = (p * (p + 1)) / 2;
	j *= v.back();
	int ans = 0;
	while (i <= j) {
		int mid = (i + j) / 2;
		bool flag = func(v, mid, p);
		if (flag) {
			ans = mid;
			j = mid - 1;
		}
		else {
			i = mid + 1;
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
