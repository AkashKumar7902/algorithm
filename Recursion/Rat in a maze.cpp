// problem statement : https://practice.geeksforgeeks.org/problems/rat-in-a-maze-problem/1#


// 1st approach - no need of visited array will benefit from the fact that the
// rat can't move to the position with value 0 on it. so we will mark the position
// which we are currently on as 0 and then move to next position ... it will make  
// sure that while getting back from recursive calls it will not get to the position we are currently on.
class Solution{
    public:
    vector<string> v;
    void ratinmaze(vector<vector<int>> &maze, string s, int i, int j, int n) {
        if(i == n - 1 && j == n - 1) {
            v.push_back(s);
            return;
        }
        if(i >= n || j >= n || i < 0 || j < 0) {
            return;
        }
        if(maze[i][j] == 0) {
            return;
        }
        maze[i][j] = 0;
        ratinmaze(maze, s + 'U', i - 1, j, n);
        ratinmaze(maze, s + 'D', i + 1, j, n);
        ratinmaze(maze, s + 'R', i, j + 1, n);
        ratinmaze(maze, s + 'L', i, j - 1, n);
        maze[i][j] = 1;
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        string s = "";
        if(m[0][0] == 0 || m[n-1][n - 1] == 0) {
            return v;
        }
        ratinmaze(m, s, 0, 0, n);
        if(v.size() == 0) {
            return v;
        }
        return v;
    }
};
 

// Another  approach -- Take you forward

void solve(int i, int j, vector<vector<int>> &arr, vector<vector<int>> &vis, string move, int n,int di[],int dj[])

{

    if (i == n - 1 and j == n - 1)

    {

        ans.push_back(move);

        return;

    }


 

    string dir="DLRU";

    for(int idx=0; idx<4; idx++){

        int nexti=i+di[idx];

        int nextj=j+dj[idx];

        if(nexti>=0 and nextj>=0 and nexti<n and nextj<n and !vis[nexti][nextj] and arr[nexti][nextj]==1){

            vis[i][j]=1;

            solve(nexti,nextj,arr,vis,move+dir[idx],n,di,dj);

            vis[i][j]=0;

        }

    }

 

}


//approach( Coding Blocks )

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

bool ratinmaze(char maze[][10], int soln[][10], int i, int j, int m, int n) {
	if (i == m and j == n) {
		soln[i][j] = 1;
		for (int i = 0; i <= m; ++i) {
			for (int j = 0; j <= n; ++j) {
				cout << soln[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl;
		return true;
	}
	if (i > m || j > n ) {
		return false;
	}
	if (maze[i][j] == 'X') {
		return false;
	}
	soln[i][j] = 1;

	bool rightsuccess = ratinmaze(maze, soln, i, j + 1, m, n);
	bool downsuccess = ratinmaze(maze, soln, i + 1, j, m, n);

	soln[i][j] = 0;

	if (rightsuccess || downsuccess) {
		return true;
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
	char maze[10][10] = {
		"0000",
		"00X0",
		"000X",
		"0X00"
	};
	int soln[10][10] = {};
	int m = 4, n = 4;
	bool ans = ratinmaze(maze, soln, 0, 0, m - 1, n - 1);
	if (ans == false) {
		cout << "path does'nt exist" << endl;
	}
}


