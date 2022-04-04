// I/P : string , abc
// O/P : abc ab ac a bc b c  

// we will use recursive tree as its the case of choices
// either we can choice a character or not from I/P string
// both will yield a different answer.

/*  
            OP      IP
            ""     "ab"
               /\   ^
              /  \       /
           X /    \    \/
            /      \
           /        \
       OP1  IP1    OP2   IP2
       ""   "b"    "a"   "b"
          /\ ^           /\
         /  \         X /  \     /
        /    \    /    /    \  \/
   X   /      \ \/    /      \
      /        \    OP1  IP1   OP2   IP2
     /          \   "a"  ""    "ab"  ""
    /            \
    OP1 IP1   OP2 IP2
    ""  ""    "b" ""    
    
    // when input gets empty u will get all the answers
*/

#include <bits/stdc++.h>
using namespace std;
using namespace placeholders;

#define ll long long

#define MOD 1000000009

void solve(string ip, string op) {
	if (ip.size() == 0) {
		cout << op << " ";
		return;
	}
	string op1 = op;
	string op2 = op;
	op1.push_back(ip[0]);
	ip.erase(ip.begin());
	solve(ip, op1);
	solve(ip, op2);
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	string ip; cin >> ip;
	string op = "";
	solve(ip, op);
}
