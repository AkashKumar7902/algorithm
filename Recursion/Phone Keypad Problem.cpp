#include <bits/stdc++.h>
using namespace std;
using namespace placeholders;

#define ll long long

#define MOD 1000000009

char keypad[][10] = {"", "", "ABC", "DEF", "GHI", "JKL", "MNO", "PQRS", "TUV", "WXYZ"};

void generate_names(char *in, char *out, int i, int j) {

	// base case
	if (in[i] == '\0') {
		out[j] = '\0';
		cout << out << endl;
		return;
	}

	// recursive case
	int digit = in[i] - '0';

	for (int k = 0; keypad[digit][k] != '\0'; ++k) {
		out[j] = keypad[digit][k];
		// fill the remaining part
		generate_names(in, out, i + 1, j + 1);
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	char in[1000];
	cin >> in;

	char out[100000];
	generate_names(in, out, 0, 0);
	return 0;
}
