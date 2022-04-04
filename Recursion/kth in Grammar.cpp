Problem statement : https://leetcode.com/problems/k-th-symbol-in-grammar/

// solution:
since there is no case of choices so use IBH.
 
   int kthGrammar(int n, int k) 
    {
        if(n == 1 and k == 1) {
            return 0;
        }
        int mid = (1 << (n - 1)) / 2;
        if(k <= mid) {
            return kthGrammar(n - 1, k);
        }
        else {
            return !kthGrammar(n - 1, k - mid);
        }
    }
