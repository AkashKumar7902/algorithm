#include <bits/stdc++.h>
using namespace std;
using namespace placeholders;

#define ll long long

#define MOD 1000000007

bool issafe(int board[][10], int i, int j, int n) {
	for (int row = 0; row < i; ++row) {
		if (board[row][j] == 1) {
			return false;
		}
	}
	int x = i;
	int y = j;
	while (x >= 0 && y >= 0) {
		if (board[x][y]) {
			return false;
		}
		x--;
		y--;
	}
	x = i;
	y = j;
	while (x >= 0 && y < n) {
		if (board[x][y] == 1) {
			return false;
		}
		x--;
		y++;
	}
	return true;
}

bool solveNqueen(int board[][10], int i, int n) {
	if (i == n) {
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				if (board[i][j] == 1) {
					cout << "Q ";
				}
				else {
					cout << "_ ";
				}
			}
			cout << endl;
		}
		cout << endl;
		return false;
	}
	for (int j = 0; j < n; ++j) {
		if (issafe(board, i, j, n)) {
			board[i][j] = 1;
			bool nextqueenrakhpaye = solveNqueen(board, i + 1, n);
			if (nextqueenrakhpaye) {
				return true;
			}
			board[i][j] = 0;
		}
	}
	return false;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n; cin >> n;
	int board[10][10] = {0};
	solveNqueen(board, 0, n);
	return 0;
}


