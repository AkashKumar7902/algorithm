


#include <bits/stdc++.h>
using namespace std;

void build(int *tree, int l, int r, int index, int *a) {
	if (l == r) {
		tree[index] = a[l];
		return;
	}
	int mid = (l + r) / 2;
	build(tree, l, mid, 2 * index, a);
	build(tree, mid + 1, r, 2 * index + 1, a);
	tree[index] = min(tree[2 * index], tree[2 * index + 1]);
}

int lazy[100000] = {};

void lazyPropagation(int *tree, int ss, int se, int qs, int qe, int inc, int index) {
	if (lazy[index] != 0) {
		tree[index] += lazy[index];
		// non-leaf node
		if (ss != se) {
			//pass the lazy value to left and right node
			lazy[2 * index] = lazy[2 * index + 1] = lazy[index];
		}
		// clear the lazy value at current node as it is already been used to increment the current node
		lazy[index] = 0;
	}
	if (ss > qe || se < qs) {
		return;
	}
	if (ss >= qs && se <= qe) {
		tree[index] += inc;
		//pass the increment value to the child nodes in form of lazy value.
		if (ss != se) { // non-leaf node
			lazy[2 * index] += inc;
			lazy[2 * index + 1] += inc;
		}
		return;
	}
	int mid = (ss + se) / 2;
	lazyPropagation(tree, ss, mid, qs, qe, inc, 2 * index);
	lazyPropagation(tree, mid + 1, se, qs, qe, inc, 2 * index + 1);
	tree[index] = min(tree[2 * index], tree[2 * index + 1]);
}

int lazyPropagationquery(int *tree, int ss, int se, int qs, int qe, int index) {

	if (lazy[index] != 0) {
		tree[index] += lazy[index];
		// non-leaf node
		if (ss != se) {
			//pass the lazy value to left and right node
			lazy[2 * index] = lazy[2 * index + 1] = lazy[index];
		}
		// clear the lazy value at current node as it is already been used to increment the current node
		lazy[index] = 0;
	}
	if (ss > qe || se < qs) {
		return INT_MAX;
	}
	if (ss >= qs && se <= qe) {
		return tree[index];
	}
	int mid = (ss + se) / 2;
	int left = lazyPropagationquery(tree, ss, mid, qs, qe, 2 * index);
	int right = lazyPropagationquery(tree, mid + 1, se, qs, qe, 2 * index + 1);
	return min(left, right);
}

int main() {
	int a[] = {1, 3, 2, -5, 6, 4};
	int n = sizeof(a) / sizeof(int);
	int *tree = new int[4 * n + 1];
	build(tree, 0, n - 1, 1, a);
	lazyPropagation(tree, 0, n - 1, 0, 2, 10, 1);
	lazyPropagation(tree, 0, n - 1, 0, 4, 10, 1);

	cout << "Q1 (1-1) : " << lazyPropagationquery(tree, 0, n - 1, 1, 1, 1) << endl;
	lazyPropagation(tree, 0, n - 1, 3, 4, 10, 1);
	cout << "Q2 (3-5) : " << lazyPropagationquery(tree, 0, n - 1, 3, 5, 1) << endl;
}




