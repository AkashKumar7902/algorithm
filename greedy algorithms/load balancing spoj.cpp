//https://www.spoj.com/problems/BALIFE/

#include <bits/stdc++.h>
using namespace std;
using namespace placeholders;
#define mem1(a) 		memset(a, 1, sizeof(a))
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

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int arr[10000];
	int n, i, val, diff;
	while (1) {
		int max_load = 0, load = 0;
		cin >> n;
		//stop taking input if n = -1
		if (n == -1) {
			break;
		}
		for (int i = 0; i < n; ++i) {
			cin >> arr[i];
			load += arr[i];
		}
		if (load % n != 0) {
			cout << -1 << endl;
			continue;
		}
		//find the load that is to distributed equally
		load = load / n;
		diff = 0;
		for (int i = 0; i < n; ++i) {
			//find the diff between final load assigned and current load
			diff += (arr[i] - load);
			max_load = max(max_load, abs(diff));
		}
		cout << max_load << endl;
	}
}
