// https://practice.geeksforgeeks.org/problems/minimum-number-in-a-sorted-rotated-array-1587115620/1/?page=1&category[]=Binary%20Search&sortBy=submissions#


int minNumber(int arr[], int low, int high)
    {
        int ans = INT_MAX;
        while(low<= high) {
            int mid = (low + high) >> 1;
            if(arr[mid] < ans) {
                ans = arr[mid];
            }
            if(arr[low] < arr[high]) {
                high--;
            }
            else {
                low++;
            }
        }
        return ans;
    }
