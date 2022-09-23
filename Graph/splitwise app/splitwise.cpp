#include <bits/stdc++.h>
using namespace std;
using namespace placeholders;
#define mem1(a) 		memset(a, 1, sizeof(a))
#define mem0(a)			memset(a, 0, sizeof(a))
#define pb push_back
#define pf push_front
#define ppb pop_back
#define ppf pop_front
#define fr first
#define sc second
#define ll long long
#define prinst(st)		for(auto &i : st) cout << i << " "; cout << endl;
#define printvec(vec) for(auto elem : vec) cout << elem << " "; cout << endl;
#define printstack(st) while(!st.empty()) cout << st.top() << " ", st.pop(), cout <<endl;

class person_compare {
public:
	bool operator()(pair<string, int> p1, pair<string, int> p2) {
		return p1.second, p2.second;
	}
};

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int no_of_transactions, friends;
	cin >> no_of_transactions >> friends;

	string x, y;
	int amount;

	map<string, int> net;

	while (no_of_transactions--) {
		cin >> x >> y >> amount;
		if (net.count(x) == 0) {
			net[x] = 0;
		}
		if (net.count(y) == 0) {
			net[y] = 0;
		}
		net[x] -= amount;
		net[y] += amount;
	}

	multiset<pair<string, int>, person_compare> m;

	for (auto p : net) {
		string person = p.first;
		int amount = p.second;

		if (net[person] != 0) {
			m.insert(make_pair(person, amount));
		}
	}

	// settlements (start, end)
	int cnt = 0;
	while (!m.empty()) {
		auto low = m.begin();
		auto high = prev(m.end());

		int debit = low->second;
		string debit_person = low->first;

		int credit = high->second;
		string credit_person = high->first;

		m.erase(low);
		m.erase(high);

		int settlement_amount = min(-debit, credit);

		debit += settlement_amount;
		credit -= settlement_amount;

		cout << debit_person << " will pay Rs." << settlement_amount << " to " << credit_person << endl;

		if (debit != 0) {
			m.insert(make_pair(debit_person, debit));
		}
		if (credit != 0) {
			m.insert(make_pair(credit_person, credit));
		}

		cnt++;
	}
	cout << cnt << endl;
}
