#include <bits/stdc++.h>
using namespace std;

void buildTree(int *a, int s, int e, int *tree, int index) {
	if (s == e) {
		tree[index] = a[s];
		return;
	}
	// Recursion
	int mid = (s + e) / 2;
	buildTree(a, s, mid, tree, 2 * index);
	buildTree(a, mid + 1, e, tree, 2 * index + 1);

	tree[index] = min(tree[2 * index], tree[2 * index + 1]);
}

int query(int *a, int ss, int se, int qs, int qe, int *tree, int index) {
	if (qe < ss || se < qs) {
		return INT_MAX;
	}
	if (qs <= ss && qe >= se) {
		return tree[index];
	}
	int mid = (ss + se) / 2;
	int left = query(tree, ss, mid, qs, qe, tree, 2 * index);
	int right = query(tree, mid + 1, se, qs, qe, tree, 2 * index + 1);
	return min(left, right);
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int a[] = {1, 3, 2, -5, 6, 4};
	int n = sizeof(a) / sizeof(int);

	int *tree = new int[4 * n + 1];
	buildTree(a, 0, n - 1, tree, 1);
	int q;
	cin >> q;
	while (q--) {
		int qs, qe;
		cin >> qs >> qe;
		qs--, qe--;
		cout << query(a, 0, n - 1, qs, qe, tree, 1);
	}
}




