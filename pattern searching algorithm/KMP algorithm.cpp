/*******************************

      For explanation,
      https://youtu.be/4jY57Ehc14Y
      
  
*******************************/


#include <bits/stdc++.h>
using namespace std;
using namespace placeholders;
#define ll long long
const ll mod = 1e9 + 7;

void computeLPSarray(string pat, int m, vector<int> &lps) {
	int len = 0;
	int i = 1;
	lps[0] = 0;
	while( i < m) {
		if(pat[i] == pat[len]) {
			lps[i] = len + 1;
			len += 1;
			i += 1;
		}
		else {
			if(len != 0) {
				len = lps[len - 1];
			}
			else {
				lps[i] = 0;
				i += 1;
			}
		}
	}
}


void kmpsearch(string pat,string txt) {
	int n = txt.size();
	int m = pat.size();
	vector<int> lps(m);
	computeLPSarray(pat, m, lps);
	int i = 0;
	int j = 0;
	while( i < n) {
		if(txt[i] == pat[j]) {
			i += 1;
			j += 1;
		}
		else {
			if(j != 0)
				j = lps[j - 1];
			else 
				i += 1;
		}
		if(j == m) {
			cout << i << " " << j << endl;
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
	string pat, txt;
	cin >> txt >> pat;
}
