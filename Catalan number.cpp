https://practice.geeksforgeeks.org/problems/handshakes1303/1/?page=2&category[]=Recursion&sortBy=submissions#

solution: https://www.youtube.com/watch?v=J3Mtaa0jv6s&t=70s

// code
int count(int N){
        vector<int> dp(N + 1);
        dp[0] = 1;
        for(int n = 2; n <= N; n += 2) {
            for(int i = 0; i <= n - 2; ++i) {
                dp[n] += dp[i] * dp[n - 2 - i];
            }
        }
        return dp[N];
    }
