//    https://hack.codingblocks.com/app/practice/1/1057/problem


// the search space is gonna be the time 
// lets take the sample length of 4 boards as [10, 20, 30, 40];
// so in the best case the minimum time required to paint the board will
// be equal to the greatest length in boards array .
// and in the worst case, a single painter would be painting all the boards
// by his own, so the total time would be the sum of all length in
// boards array.

// -----------------------------------
// 40             70                 100
// start          mid                end


// now we will check if it is possible to 
// paint all boards in 70 minutes(mid) ? 
// in other words, we are gonna
// calculate the no of painters required to paint
// the boards in 70 minutes. and if the no. of 
// painters found is greater than the available painters we would 
// reject the mid element and update s = mid + 1;
// in the other case when the no. of painters required to 
// paint all boards in 70 minutes comes out to be less than or equal to
// the mid element simply update e = mid - 1 and also update the answer variable
// to store the value of mid.


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

bool check(vector<int> &v, int x, int t) {
	int painter = 0;
	int time = 0;
	for (int i = 0; i < v.size(); ++i) {
		if (time + v[i] > t) {
			time = v[i];
			painter++;
			if (painter > x) {
				return false;
			}
		}
		else {
			time += v[i];
		}
	}
	return true;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int k, n;
	cin >> k >> n;
	vector<int> v(n);
	int e = 0;
	for (int i = 0; i < n; ++i) {
		cin >> v[i];
		e += v[i];
	}
	int ans = 0;
	sort(v.begin(), v.end());
	int s = v.back();
	while (s <= e) {
		int mid = (s + e) / 2;
		bool flag = check(v, k, mid);
		if (check) {
			ans = mid;
			e = mid - 1;
		}
		else {
			s = mid + 1;
		}
	}
	cout << ans << endl;
}
