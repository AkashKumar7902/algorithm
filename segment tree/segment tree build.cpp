#include <bits/stdc++.h>
using namespace std;
using namespace placeholders;

void buildtree(int *a, int s, int e, int *tree, int index) {
	if (s == e) {
		tree[index] = a[s];
		return;
	}
	// Recursive case
	int mid = (s + e) / 2;
  // post order traversal - first we build left and right side tree and then build the current node.
	buildtree(a, s, mid, tree, 2 * index);
	buildtree(a, mid + 1, e, tree, 2 * index + 1);

	tree[index] = min(tree[2 * index], tree[2 * index + 1]);
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
	buildtree(a, 0, n - 1, tree, 1);
	for(int i = 1; i <= 13; ++i) {
    cout << tree[i] << " ";
  }
  cout << endl;
}




