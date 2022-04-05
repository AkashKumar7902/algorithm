// you need to count the pair of elements in 
// array a where a[i] < a[j] , i < j;

#include <bits/stdc++.h>
using namespace std;
using namespace placeholders;

#define ll long long

#define MOD 1000000009

int merge(int *a, int s, int e) {
	int mid = (s + e) / 2;
	int i = s;
	int j = (mid + 1);
	int k = s;

	int temp[100000];

	int cnt = 0; // cross inversion

	while (i <= mid and j <= e) {
		if (a[i] <= a[j]) {
			temp[k++] = a[i++];
		}
		else {
			temp[k++] = a[j++];
			cnt += mid - i + 1;
		}
	}

	// fill the array if some elements are left in one of the arrays
	while (i <= mid) {
		temp[k++] = a[i++];
	}
	while (j <= e) {
		temp[k++] = a[j++];
	}

	// copy all elements back to array a
	for (int i = s; i <= e; ++i) {
		a[i] = temp[i];
	}
	return cnt;
}

int inversion_count(int *a, int s, int e) {
	// Base Case
	if (s >= e) {
		return 0;
	}
	// merge sort
	int mid = (s + e) / 2;
	int x = inversion_count(a, s, mid);
	int y = inversion_count(a, mid + 1, e);
	int z = merge(a, s, e);  // cross-inversion
	return x + y + z;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int arr[] = {1, 5, 2, 6, 3, 0};
	int n = sizeof(arr) / sizeof(int);
	cout << inversion_count(arr, 0, n - 1);
}
