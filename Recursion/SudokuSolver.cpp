 vector<vector<string>> ans;
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
        vector<string> temp;
		for (int i = 0; i < n; ++i) {
            string s;
			for (int j = 0; j < n; ++j) {
				if (board[i][j] == 1) {
                    s.push_back('Q');
				}
                else {
                    s.push_back('.');
                }
            }
            temp.push_back(s);
		}
        ans.push_back(temp);
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


// Another Approach (coding Blocks)
#include <bits/stdc++.h>
using namespace std;
using namespace placeholders;
#define mem1(a) 		memset(a, -1, sizeof(a))
#define mem0(a)			memset(a, 0, sizeof(a))
#define pb push_back
#define pf push_front
#define ppb pop_back
#define ppf pop_front
#define fr first
#define sc second
#define ll long long
#define printst(st)		for(auto &i : st) cout << i << " "; cout << endl;
#define printvec(vec) for(auto elem : vec) cout << elem << " "; cout << endl;
#define printstack(st) while(!st.empty()) cout << st.top() << " ", st.pop(), cout <<endl;
#define MOD 1000000007

bool canPlace(int mat[][9], int i, int j, int n, int number) {
	for (int x = 0; x < n; ++x) {
		if (mat[x][j] == number || mat[i][x] == number) {
			return false;
		}
	}
	int rn = sqrt(n);
	int sx = (i / rn) * rn;
	int sy = (j / rn) * rn;

	for (int x = sx; x < sx + rn; ++x) {
		for (int y = sy; y < sy + rn; ++y) {
			if (mat[x][y] == number) {
				return false;
			}
		}
	}
	return true;
}

bool solveSudoku(int mat[][9], int i, int j, int n) {
	if (i == n) {
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				cout << mat[i][j] << " ";
			}
			cout << endl;
		}
		return true;
	}
	if (j == n) {
		return solveSudoku(mat, i + 1, 0, n);
	}
	if (mat[i][j] != 0) {
		return solveSudoku(mat, i, j + 1, n);
	}
	for (int number = 1; number <= n; ++number) {
		if (canPlace(mat, i, j, n, number)) {
			mat[i][j] = number;
			bool couldWeSolve = solveSudoku(mat, i, j + 1, n);
			if (couldWeSolve) {
				return true;
			}
			mat[i][j] = 0;
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
	int mat[9][9] =  {
		{3, 0, 6, 5, 0, 8, 4, 0, 0},
		{5, 2, 0, 0, 0, 0, 0, 0, 0},
		{0, 8, 7, 0, 0, 0, 0, 3, 1},
		{0, 0, 3, 0, 1, 0, 0, 8, 0},
		{9, 0, 0, 8, 6, 3, 0, 0, 5},
		{0, 5, 0, 0, 9, 0, 6, 0, 0},
		{1, 3, 0, 0, 0, 0, 2, 5, 0},
		{0, 0, 0, 0, 0, 0, 0, 7, 4},
		{0, 0, 5, 2, 0, 6, 3, 0, 0}
	};
	solveSudoku(mat, 0, 0, 9);
}
