class Solution {
    /** 
     *@param A : an integer sorted array
     *@param target :  an integer to be inserted
     *return : a list of length 2, [index1, index2]
     */
public:
    vector<int> searchRange(vector<int> &A, int target) {
        // write your code here
        vector<int> res(2);
        res[0] = res[1] = -1;
        if (A.empty()) {
            return res;
        }
        int start = 0, end = A.size() - 1, mid;
        while (start + 1 < end) {
            mid = start + (end - start) / 2;
            if (A[mid] == target) end = mid;
            else if (A[mid] < target) start = mid;
            else end = mid;
        }
        if (A[start] == target) res[0] = start;
        else if (A[end] == target) res[0] = end;
        else return res;
        start = 0, end = A.size() - 1;
        while (start + 1 < end) {
            mid = start + (end - start) / 2;
            if (A[mid] == target) start = mid;
            else if (A[mid] < target) start = mid;
            else end = mid;
        }
        if (A[end] == target) res[1] = end;
        else if (A[start] == target) res[1] = start;
        else return res;
        return res;
    }
};
