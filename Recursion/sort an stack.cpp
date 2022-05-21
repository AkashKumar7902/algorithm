#include <bits/stdc++.h>
using namespace std;
using namespace placeholders;

void insert(stack<int> &st, int temp) {
	if (st.size() == 0 || st.top() <= temp) {
		st.push(temp);
		return;
	}
	int temp2 = st.top();
	st.pop();
	insert(st, temp);
	st.push(temp2);
	return;
}

void sortStack(stack<int> &st) {
	if (st.size() == 1) {
		return;
	}
	int temp = st.top();
	st.pop();
	sortStack(st);
	insert(st, temp);
}

void printAsscending(stack<int> st) {
	if (st.size() == 0) {
		return;
	}
	int temp = st.top();
	st.pop();
	printAsscending(st);
	cout << temp << ", ";
	// st.push(temp); (not required)
}

void printDescending(stack<int> st) {
	if (st.size() == 0) {
		return;
	}
	int temp = st.top();
	st.pop();
	cout << temp <<  ", ";
	printDescending(st);
	// st.push(temp); (not required)
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n; cin >> n;
	stack<int> st;
	int elem;
	for (int i = 0; i < n; ++i) {
		cin >> elem;
		st.push(elem);
	}
	sortStack(st);
	printAsscending(st);
	cout << endl;
	printDescending(st);
}




