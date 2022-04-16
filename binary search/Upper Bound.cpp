/*
  If we find the key element, then don't stop
  if we want to get the last occurence (or upper bound)
  then explore the right part of the array... i.e. 
  set (s = mid + 1)
*/

#include <bits/stdc++.h>
using namespace std;
using namespace placeholders;

int upperBound(int a[], int n, int key) {
	int s = 0;
	int e = n - 1;
	int ans = -1;
	while(s <= e) {
		int mid = (s + e) / 2;
		if(a[mid] == key) {
			ans = mid;
			s = mid + 1;
		}
		else if(a[mid] < key) {
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
	cout << upperBound(a, n, key) << endl;
}


