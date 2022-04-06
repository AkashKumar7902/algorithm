//both iterative and recursive


// iterative
// Optimized implementation of Bubble sort
#include <bits/stdc++.h>
using namespace std;
void swap(int *xp, int *yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}

// An optimized version of Bubble Sort
void bubbleSort(int arr[], int n)
{
int i, j;
bool swapped;
for (i = 0; i < n-1; i++)
{
	swapped = false;
	for (j = 0; j < n-i-1; j++)
	{
		if (arr[j] > arr[j+1])
		{
		swap(&arr[j], &arr[j+1]);
		swapped = true;
		}
	}

	// IF no two elements were swapped by inner loop, then break
	if (swapped == false)
		break;
}
}

/* Function to print an array */
void printArray(int arr[], int size)
{
	int i;
	for (i = 0; i < size; i++)
		cout <<" "<< arr[i];
	cout <<" n";
}

// Driver program to test above functions
int main()
{
	int arr[] = {64, 34, 25, 12, 22, 11, 90};
	int n = sizeof(arr)/sizeof(arr[0]);
	bubbleSort(arr, n);
	cout <<"Sorted array: \n";
	printArray(arr, n);
	return 0;
}


// recursive

#include <bits/stdc++.h>
using namespace std;
using namespace placeholders;

#define ll long long

#define MOD 1000000009

// full iterative
void bubbleSort(int a[], int n)
{
	int i, j;
	for (i = 0; i < n - 1; i++) {// no of passes
		// Last i elements are already in place
		for (j = 0; j < n - i - 1; j++) {
			if (a[j] > a[j + 1]) {
				swap(a[j], a[j + 1]);
			}
		}
	}
}

// half iterative half recursive
// we only apply recursion on the outer loop of the iterative version of bubble sort
void bubble_sort(int a[], int n) {
	// base case
	if (n == 1) {
		return;
	}

	// rec case
	// after you have moved the largest element in the current part to the end of the array by pairwise swapping
	for (int j = 0; j < n - 1; ++j) {
		if (a[j] > a[j + 1]) {
			swap(a[j], a[j + 1]);
		}
	}
	// sort the first n - 1 elements
	bubble_sort(a, n - 1);
}

// full recursive
// we apply recursive on both inner and outer loops of the iterative versions of bubble sort
// in this approach we keep two variables j and n
// where j is gonna keep track of the inner loop swapping
// and n is gonna count the no. of passes through the array

void bubble_sort_recursive(int a[], int j, int n) {
	// base case
	if (n == 1) {
		return;
	}
	if (j == n - 1) {
		//single pass of the current array has been done
		return bubble_sort_recursive(a, 0, n - 1);
	}
	// recursive case
	if (a[j] > a[j + 1]) {
		swap(a[j], a[j + 1]);
	}
	bubble_sort_recursive(a, j + 1, n);
	return;
}
int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n; cin >> n;
	int arr[n];
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}
	bubble_sort_recursive(arr, 0, n);
	for (int i = 0; i < n; ++i) {
		cout << arr[i] << " ";
	}
	cout << endl;
}
