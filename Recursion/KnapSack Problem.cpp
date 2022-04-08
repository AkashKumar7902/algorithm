/*
  There is a Thief with a bag of capacity c kg .
  This means he cannot steal more than c kgs of items
  
  in the store there is 
                 bag     ball    football      bat
  Weight         1kg     2kg      3kg         5kg
  Price          40`     20       35          100
  
  What is the maximum profit he can make ? 
 
*/

/*
  Solution :

  w1, w2, w3, ........... wn-1
  p1, p2, p3, ........... pn-1
  
  --->  if we take the last item then 
  include = pn-1 + profit(n-1, c - wt(n - 1))
              ^
              |
              |
       This case will be calculated by recursion
  But this case can only work if c >= wt(n-1)
  
  -->   else if we don't include the last item
  exclude = pn-1 + profit(n - 1, C)
              ^
              |
              |
       This case will be calculated by recursion


Now, the solution will be maximum of include and exclude.

*/



int knapSack(int W, int wt[], int val[], int n) 
    { 
        if(n == 0 or W == 0) {
            return 0;
        }
        int ans = 0;
        int inc, exc;
        inc = exc = 0;
        if(wt[n - 1] <= W) {
            inc = val[n - 1] + knapSack(W - wt[n - 1], wt, val, n - 1);
        }
        exc = knapSack(W, wt, val, n - 1);
        ans = max(inc, exc);
        return ans;
    }
