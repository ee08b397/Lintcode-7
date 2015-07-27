#include <vector>

class Solution {
public:
    /**
     * @param A an integer array
     * @return  A list of integers includes the index of
     *          the first number and the index of the last number
     */
    vector<int> continuousSubarraySum(vector<int>& A) {
        // Write your code here
        vector<int> res;
        if (A.empty()) return res;
        int left = 0, right = 0, maxsum = A[0], cnt = A[0], pos = 0;
        for (int i = 1; i < A.size(); i ++) {
            if (cnt < 0) {
                cnt = A[i];
                pos = i;
            } else {
                cnt += A[i];
            }
            if (cnt > maxsum) {
                maxsum = cnt;
                left = pos;
                right = i;
            }
        }
        res.push_back(left);
        res.push_back(right);
        return res;
    }
};
