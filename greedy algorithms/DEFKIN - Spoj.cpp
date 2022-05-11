https://www.spoj.com/problems/DEFKIN/

#include <bits/stdc++.h>
using namespace std;

void solve() {
	int w, h, n; cin >> w >> h >> n;
	if (n == 0) {
		cout << w * h << endl;
		return;
	}
	vector<int> x(n), y(n);
	int xi = 0, yi = 0;
	for (int i = 0; i < n; ++i) {
		cin >> xi >> yi;
		x[i] = xi, y[i] = yi;
	}

	sort(x.begin(), x.end());
	sort(y.begin(), y.end());
	int dx = x[0] - 1;
	int dy = y[0] - 1;
	for (int i = 1; i < n; ++i) {
		dx = max(dx, x[i] - x[i - 1] - 1);
		dy = max(dy, y[i] - y[i - 1] - 1);
	}
	//corner case(last tower to grid end)
	dx = max(dx, w - x[n - 1]);
	dy = max(dy, h - y[n - 1]);
	cout << dx * dy << endl;
}

int main() {
	int t; cin >> t;
	while (t--) {
		solve();
	}
}
