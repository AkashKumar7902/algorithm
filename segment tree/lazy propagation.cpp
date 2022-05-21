/* Optimisation over range based update in segment tree
   Takes O(logN) time 
*/

int lazy[100000] = {};

// ss is the start of the range of indices in tree
// se is the end of the range of indices in tree
// qs in the start index of the range to be updated
// qe is the start index of the range to be updated
// inc is the amount by which the range of indices has to be updated

void lazyPropagation(int *tree, int ss, int se, int qs, int qe, int inc, int index) {
	if (lazy[index] != 0) {
		tree[index] += lazy[index];
		// non-leaf node
		if(ss != se) {
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
		if(ss != se) { // non-leaf node
			lazy[2 * index] += inc;
		    lazy[2 * index + 1] += inc;  
		}
		return;
	}
  
  // Recursive Case - Partial Overlap
	int mid = (ss + se) / 2;
	lazyPropagation(tree, ss, mid, qs, qe, inc, 2 * index);
	lazyPropagation(tree, mid + 1, se, qs, qe, inc, 2 * index + 1);
	tree[index] = min(tree[2 * index], tree[2 * index + 1]);
}

