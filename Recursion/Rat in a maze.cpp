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

