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

