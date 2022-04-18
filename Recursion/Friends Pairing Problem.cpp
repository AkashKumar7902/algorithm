
// Problem statement : https://practice.geeksforgeeks.org/problems/friends-pairing-problem5425/1/#

// Recursive
//   f(N) = 1 * f(N - 1) +   (N - 1)C1 * f(N - 2) 
//                                        Two went 
//                                      as a couple

int f(int n) {
	if (n <= 1) {
		return 1;
	}
	return f(n - 1) + (n - 1) * f(n - 2);
}

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
