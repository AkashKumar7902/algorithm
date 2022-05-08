/*

There are n white dots and n black dots, equally space 
in a line.
you want to connect each white dot with any one black dot.
What is the minimum total length of wire you will need.

Input : 
      White dot position = []
      black dot position = []

E.g. test case:
I/P : 
  White dot position: [3, 4, 1];
  Black dot position: [2, 5, 6]
O/P:
  5

*/


/*
ideal approach(greedy) :
connect white with nearest black.

for the approach to work efficiently
sort both the arrays and find the difference of positions 
between black and white dots.

*/

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
	int n; cin >> n;
	int white[n] = {};
	int black[n] = {};
	for (int i = 0; i < n; ++i) {
		cin >> white[i];
	}
	for (int i = 0; i < n; ++i) {
		cin >> black[i];
	}
	sort(white, white + n);
	sort(black, black + n);
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		ans += abs(white[i] - black[i]);
	}
	cout << ans << endl;
}
