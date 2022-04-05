/*
we will first look at the function where
we are gonna print all the indices where
a[i] == key.

In the next function we are gonna store the 
indices of occurences in an output array.
*/

#include <bits/stdc++.h>
using namespace std;
using namespace placeholders;

#define ll long long

#define MOD 1000000009

void allocc(int *a, int i, int n, int key) {
	if (i == n) {
		return;
	}
	if (a[i] == key) {
		cout << i << " ";
	}
	allocc(a, i + 1, n, key);
}

int storeocc(int *a, int i, int n, int key, int *out, int j) {
	//base case
	if (i == n) {
		return j;
	}
	if (a[i] == key) {
		out[j] = i;
		//increment j to accomoadate current occ
		return storeocc(a, i + 1, n, key, out, j + 1);
	}
	// remains unchanged
	return storeocc(a, i + 1, n, key, out, j);
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
	int out[1000];
	allocc(arr, 0, n, key);
	cout << endl;
	int cnt = storeocc(arr, 0, n, key, out, 0);
	for (int k = 0; k < cnt; ++k) {
		cout << out[k] << " ";
	}
	cout << endl;
	return 0;
}
