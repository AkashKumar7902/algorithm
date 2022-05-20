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

void updatePoint(int *tree, int ss, int se, int indq, int inc, int index) {
	if (indq < ss || indq > se) {
		return;
	}
	if (ss == se) {
		tree[index] += inc;
		return;
	}
	// otherwise
	int mid = (ss + se) / 2;
	updatePoint(tree, ss, mid, indq, inc, 2 * index);
	updatePoint(tree, mid + 1, se, indq, inc, 2 * index + 1);
	tree[index] = min(tree[2 * index], tree[2 * index + 1]);
}

int main() {
	int a[] = {1, 3, 2, -5, 6, 4};
	int n = sizeof(a) / sizeof(int);

	int *tree = new int[4 * n + 1];
	buildTree(a, 0, n - 1, tree, 1);

	int increment;
	cin >> increment;
	int ind; cin >> ind;
	updatePoint(tree, 0, n - 1, ind, increment, 1);
	for (int i = 1; i <= 13; ++i) {
		cout << tree[i] << " ";
	}
}




