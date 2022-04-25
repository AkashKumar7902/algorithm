 bool isPossible(int arr[], int n, int m, int curr_min) {
        int studentUsed = 1;
        int pages_reading = 0;
        for(int i = 0; i < n; ++i) {
            if(pages_reading + arr[i] > curr_min) {
                studentUsed++;
                pages_reading = arr[i];
                if(studentUsed > m) {
                    return false;
                }
            }
            else {
                pages_reading += arr[i];
            }
        }
    }
    //Function to find minimum number of pages.
    int findPages(int A[], int N, int M) 
    {
        long long sum = 0;
        if(M > N){
            return -1;
        }
        for(int i = 0; i < N; ++i) {
            sum += A[i];
        }
        int s = A[N - 1];
        int e= sum;
        int ans = -1;
        
        while(s <= e) {
            int mid = (s + e) / 2;
            if(isPossible(A, N, M, mid)) {
                e = mid -1;
                ans = mid;
            }
            else {
                s= mid + 1;
            }
        }
        return ans;
    }
