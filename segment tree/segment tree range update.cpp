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

void updateRange(int *tree, int ss, int se, int qs, int qe, int inc, int index) {
	if (qs > se || qe < ss) {
		return;
	}
	// leaf node
	if (ss == se) {
		tree[index] += inc;
		return;
	}
	int mid = (ss + se) / 2;
	updateRange(tree, ss, mid, qs, qe, inc, 2 * index);
	updateRange(tree, mid + 1, se, qs, qe, inc, 2 * index + 1);
	tree[index] = min(tree[2 * index], tree[2 * index + 1]);
	return;
}

int main() {
  
	int a[] = {1, 3, 2, -5, 6, 4};
	int n = sizeof(a) / sizeof(int);

	int *tree = new int[4 * n + 1];
	buildTree(a, 0, n - 1, tree, 1);
	int qs, qe;
	cin >> qs >> qe;
	int increment;
	cin >> increment;
	updateRange(tree, 0, n - 1, qs, qe, increment, 1);
	for (int i = 1; i <= 13; ++i) {
		cout << tree[i] << " ";
	}
}




