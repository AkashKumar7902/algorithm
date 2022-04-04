// Josephus was a soldier in Jews army fighting against Russian army
// while fighting in the battle they were about to lose.
// so he along with his fleet went inside a cave and blocked the entrance 
// but the russian army was powerful and Josephus knew that they will come in 
// and kill everyone.
// so the army decided that it would be better to kill each other instead of 
// being killed by russian army. so they want to draw out a scheme.
// Josephus proposed a very intelligent scheme.
// He said that all the army members will stand on a circle and
// the counting will begin from someone and he will count till a particular number k
// upon counting k soldiers in circle, the kth soldier is gonna killed and 
// next step the counting will be done by the soldier adjacent to the one killed
// at the end only one soldier will be alive and he should commit suicide.
// But Josephus choosed such a number of K that he will be the last person to survive.
// instead of doing suicide, he surrended himself to the Russian army.

// This means Josephus knew recursion because this can be solved through recursion.

// since choices are not there so we will approach by IBH.


void solve(vector<int> &v, int k, int index, int &ans) {
        if(v.size() == 1) {
            ans = v[0];
            return;
        }
        index =(index + k) % v.size();
        v.erase(v.begin() + index);
        solve(v, k, index, ans);
    }
    
    int safePos(int n, int k) {
        vector<int> v;
        for(int i = 1; i <= n; ++i) {
            v.push_back(i);
        }
        int ans = -1;
        int index = 0;
        k--;
        solve(v, k, index, ans);
        return ans;
    }
