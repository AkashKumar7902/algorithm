//https://www.spoj.com/problems/KQUERY/

/* to solve this problem we will create a segment tree 
   with each node as vector containing elements from start
   to end, the vector will contain the sorted range.
*/

/* After creating a vector we will query through the tree
   if we found the range which completely overlaps with our
   query range then we would find the no of elements greater
   than k in the vector at that node containing elements in 
   that range ... we can do so by calulating upper_bound
   which will return us the iterator of the element with value just greater
   than k, then we can find the index of that element by subtracting
   the begin() iterator and then we would subtract the whole term by
   size of the vector in that node to get the no of elements greater than k;
 */


#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 100005;
int a[N];

struct segmenttree_of_vectors {
	vector<int> st[N * 4];
	void build(int start, int end, int node) {
		if(start == end) {
			st[node].push_back(a[start]);
			return;
		}
		int mid = (start + end) >> 1;
		build(start, mid, 2 * node);
		build(mid + 1, end, 2 * node + 1);
		merge(st[2 * node].begin(), st[2 * node].end(), st[2 * node + 1].begin(), st[2 * node + 1].end(), back_inserter(st[node]));
	}
	int query(int start, int end, int l, int r, int k, int node) {
		if(start > r || end < l) {
			return 0;
		}
		if(start >= l && end <= r) {
			return (st[node].size() - (upper_bound(st[node].begin(), st[node].end(), k) - st[node].begin()));
		}
		int mid = (start + end) >> 1;
		int left = query(start, mid, l, r, k, 2 * node);
		int right = query(mid + 1, end, l, r, k, 2 * node + 1);
		return left + right;
	}
} tree;

main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	
	int i, j, k, n, m, ans = 0, cnt = 0;
	cin >> n;
	for(int i = 0; i < n;++i) {
		cin >> a[i];
	}
	tree.build(0, n - 1, 1);
	cin >> m;
	while(m --) {
		int l, r, k;
		cin >> l >> r >> k;
		ans = tree.query(0, n - 1, l - 1, r - 1, k, 1);
		cout << ans << endl;
	}
	return 0;
}
