class Solution {
    /**
     * param A : an integer sorted array
     * param target :  an integer to be inserted
     * return : an integer
     */
public:
    int searchInsert(vector<int> &A, int target) {
        // write your code here
        int len = A.size();
        if (len == 0) return 0;
        int left = 0, right = len - 1, mid;
        while (left <= right) {
            mid = (left + right) / 2;
            if (A[mid] >= target) {
                if (mid == 0) return 0;
                else if (A[mid-1] < target) return mid;
                else right = mid - 1;
            } else {
                if (mid == len - 1) return len;
                else if(A[mid+1] > target) return mid + 1;
                else left = mid + 1;
            }
        }
    }
};
