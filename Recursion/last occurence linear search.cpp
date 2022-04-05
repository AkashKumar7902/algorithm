/*
we are first building the call stack 
by calling recursive function and then
building the solution.
the topmost call in the call stack will return -1
to the second call from the top. the second call
is gonna check if the first element in it is 
equal to the key if yes it is gonna return 0
because its present in its 0 index.
and this 0 will propagate upwards , 
each time incrementing by 1 on every call stack
as the element present on a smaller array at index 0
will be present at index 1 in the array containing 
one additional element in the left most side.

*/

int lastocc(int *a, int n, int key) {
	if (n == 0) {
		return -1;
	}
	int i = lastocc(a + 1, n - 1, key);
	if (i == -1) {
		if (a[0] == key) {
			return 0;
		}
		else {
			return -1;
		}
	}
	return i + 1;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int arr[] = {1, 2, 3, 7, 4, 5, 6, 7, 10};
	int key = 7;
	int n = sizeof(arr) / sizeof(int);
	cout << lastocc(arr, n, key);
	return 0;
}
