class Solution {
    /** 
     * param A : an integer sorted array
     * param target :  an integer to be inserted
     * return : an integer
     */
public:
    int searchInsert(vector<int> &A, int target) {
        // write your code here
        if (A.empty()) return 0;
        int start = 0, end = A.size() - 1, mid;
        while (start + 1 < end) {
            mid = start + (end - start) / 2;
            if (A[mid] >= target) end = mid;
            else start = mid;
        }
        if (A[start] >= target) return start;
        else if (A[end] >= target) return end;
        return A.size();
    }
};
