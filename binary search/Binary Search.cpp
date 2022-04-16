#include <bits/stdc++.h>
using namespace std;
using namespace placeholders;

int binarysearch(int a[], int n, int key) {
	int s = 0;
	int e = n - 1;
	while (s <= e) {
		int mid = (s + e) / 2;
		if (a[mid] == key) {
			return mid;
		}
		else if (a[mid] < key) {
			s = mid + 1;
		}
		else {
			e = mid - 1;
		}
	}
	return -1;
}

int main() {
	int a[1000000];
	int n; cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	int key;
	cin >> key;
	cout << binarysearch(a, n, key) << endl;
}


