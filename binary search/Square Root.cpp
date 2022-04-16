// Problem : find the square root of n with a given precision
// I/P : n = 10, precision = 3.
// O/P : 3.162

// Time complexity : O(logN + precision)
// O(logN) is the time complexity of binary search
// and O(precision) is the time complexity of calculating a precised number


#include <bits/stdc++.h>
using namespace std;

int precision;
float squareRoot(int n) {
	int s = 0;
	int e = n;
	float ans = -1;
	while (s <= e) {
		int mid = (s + e) >> 1;
		if (mid * mid == n) {
			return mid;
		}
		if (mid * mid < n) {
			ans = mid; // possible candidate..
			// but we wont stop as we want n such that ans**2 is closest to n.
			// Note : every number before mid is also a possible candidate
			// but since we need mid ** 2 to be as close as to 'n'
			// so we are gonna discard the left part of mid.
			// so lets search the right part of mid by setting s = mid + 1;
			s = mid + 1;
		}
		else {
			// mid ** 2 is overshoting n so discard the numbers greater
			// than mid by setting e = mid - 1.
			e = mid - 1;
		}
	}
	float inc = 0.1;
	for (int times = 1; times <= precision; times++) {
		while (ans * ans <= n) {
			ans = ans + inc;
		}
		// overshoot the value
		ans = ans - inc;
		inc = inc / 10;
	}
	return ans;
}

int main() {
	int n; cin >> n;
	cin >> precision;
	cout << squareRoot(n);
}


