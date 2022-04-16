/*
  if we find the mid element to be equal to key
  then don't stop .
  start exploring the left part of the array with respect
  to key by setting (end = mid - 1). By doing this we can find the first occurence of 
  the key in the sorted array.
*/

#include <bits/stdc++.h>
using namespace std;
using namespace placeholders;

int lowerBound(int a[], int n, int key) {
	int s = 0;
	int e = n - 1;
	int ans = -1;
	while (s <= e) {
		int mid = (s + e) / 2;
		if (a[mid] == key) {
			ans = mid;
			e = mid - 1;
		}
		else if (a[mid] < key) {
			s = mid + 1;
		}
		else {
			e = mid - 1;
		}
	}
	return ans;
}

int main() {
	int a[1000000];
	int n; cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	int key;
	cin >> key;
	cout << lowerBound(a, n, key) << endl;
}


