
// Problem statement : https://practice.geeksforgeeks.org/problems/friends-pairing-problem5425/1/#


// space optimised solution (better than DP)

int countFriendsPairings(int n) 
    { 
        long long a = 1; 
        long long b = 1, c;
        long long MOD = 1000000007;
        for(long long i = 2; i <= n; ++i) {
            c = (((((i-1)* a)+ MOD)% MOD) +  b) % MOD;
            a = b;
            b = c;
        }
        return (int)b;
    }
