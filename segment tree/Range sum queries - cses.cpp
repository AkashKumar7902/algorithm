//https://cses.fi/problemset/task/1646/


#include <bits/stdc++.h>
using namespace std;
using namespace placeholders;

#define ll long long

void build(ll *tree, ll l, ll r, ll index, ll *a) {
	if (l == r) {
		tree[index] = a[l];
		return;
	}
	ll mid = (l + r) / 2;
	build(tree, l, mid, 2 * index, a);
	build(tree, mid + 1, r, 2 * index + 1, a);
	tree[index] = tree[2 * index] + tree[2 * index + 1];
}

int lazy[900000] = {};

// for updates
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
	tree[index] = tree[2 * index] + tree[2 * index + 1];
}

ll lazyPropagationquery(ll *tree, ll ss, ll se, ll qs, ll qe, ll index) {


	if (ss > qe || se < qs) {
		return 0;
	}
	if (ss >= qs && se <= qe) {
		if (lazy[index] != 0) {
			tree[index] += (lazy[index] + (se - ss + 1) * 10);
		}
		return tree[index];
	}
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
	ll mid = (ss + se) / 2;
	ll left = lazyPropagationquery(tree, ss, mid, qs, qe, 2 * index);
	ll right = lazyPropagationquery(tree, mid + 1, se, qs, qe, 2 * index + 1);
	return left + right;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	ll n; cin >> n;
	ll q; cin >> q;
	ll a[n];
	for (ll i = 0; i < n; ++i) {
		cin >> a[i];
	}
	ll *tree = new ll[4 * n + 1];
	build(tree, 0, n - 1, 1, a);
	while (q--) {
		ll l, r; cin >> l >> r;
		cout << lazyPropagationquery(tree, 0, n - 1, l - 1, r - 1, 1) << endl;

	}

}




