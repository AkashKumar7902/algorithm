#include <bits/stdc++.h>
using namespace std;
using namespace placeholders;

#define ll long long

#define MOD 1000000009

// First Approach
int firstocc(int *a, int n, int key) {
	if (n == 0) {
		return -1;
	}
	if (a[0] == key) {
		return 0;
	}
	int i = firstocc(a + 1, n - 1, key);
	if (i == -1) {
		return -1;
	}
	return i + 1;
}

// Second Approach (more like a for loop)
int firstocc1(int *a, int i, int n, int key) {
	if (i == n) {
		return -1;
	}
	if (a[i] == key) {
		return i;
	}
	return firstocc1(a, i + 1, n, key);
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int arr[] = {1, 2, 3, 7, 4, 5, 6, 7, 10};
	int key = 7;
	int n = sizeof(arr) / sizeof(int);
	cout << firstocc(arr, n, key) << endl;
	cout << firstocc1(arr, 0, n, key) << endl;
	return 0;
}
