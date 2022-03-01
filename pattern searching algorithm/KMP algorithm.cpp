/*******************************

      For explanation,
      https://youtu.be/4jY57Ehc14Y
      
  
*******************************/


#include <bits/stdc++.h>
using namespace std;
using namespace placeholders;
#define ll long long
const ll mod = 1e9 + 7;

void computelps(string pat, int m, vector<ll> &lps) {
	int len = 0;
	int i = 1;
	lps[0] = 0;
	while (i < m) {
		if (pat[i] == pat[len]) {
			lps[i] = len + 1;
			len++;
			i++;
		}
		else {
			if (len != 0)
				len = lps[len - 1];
			else {
				lps[i] = 0;
				i++;
			}
		}
	}
}

void kmpsearch(string text, string pat) {
	ll n = text.size();
	ll m = pat.size();
	vector<ll> lps(m);
	computelps(pat, m, lps);
	ll i = 0;
	ll j = 0;
	while (i < n) {
		if (text[i] == pat[j]) {
			i++;
			j++;
		}
		else {
			if (j != 0) {
				j = lps[j - 1];
			}
			else {
				i ++;
			}
		}
		if (j == m) {
			cout << i - j << endl; 	// prints the index at which the pattern starts in string text
			j = lps[j - 1];
		}
	}
}



int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	string text, pat;
	while (cin >> text >> pat) {
		kmpsearch(text, pat);
	}
}
