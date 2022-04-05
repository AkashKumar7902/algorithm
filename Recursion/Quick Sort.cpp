/*
  quick sort is basically a divide and conquer algorithm
  it works in O(NLogN) in average case
  and O(n) in worst case.
*/

/*    
    pivot element is basically the last element of the array
    we break the array into two parts the first part containing only
    elements less than pivot element and the second part containing
    only elements more than pivot element.
    We will sort the two parts through recursion.
    quicksort(a, s, p - 1);
    quicksort(a, p + 1, e);
    
*/

#include <bits/stdc++.h>
using namespace std;
using namespace placeholders;

#define ll long long

#define MOD 1000000009

int partition(int *a, int s, int e) {
	// inplace (cant take extra array)
	// so we are gonna partition via pointers
	int i = s - 1;
	int j = s;

	int pivot = a[e];

	for (; j <= e - 1; ) {
		if (a[j] <= pivot) {
			// merge the smaller element in the region 1
			i += 1;
			swap(a[i], a[j]);
		}
		// expand the larger region.
		j = j + 1;
	}
	// place the pivot element in the correct index
	swap(a[i + 1], a[e]);
	return i + 1;
}

void quicksort(int *arr, int s, int e) {

	//base case
	if (s >= e ) {
		return;
	}

	// recursive case
	int p = partition(arr, s, e);
	//left part
	quicksort(arr, s, p - 1);
	// right part
	quicksort(arr, p + 1, e);

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
	quicksort(arr, 0, n - 1);
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}
