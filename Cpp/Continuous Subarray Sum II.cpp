#include <vector>

class Solution {
public:
    /**
     * @param A an integer array
     * @return  A list of integers includes the index of
     *          the first number and the index of the last number
     */
    vector<int> continuousSubarraySumII(vector<int>& A) {
        // Write your code here
        vector<int> res;
        //if (A.empty()) return res;
        int len = A.size(), sum = 0;
        for (int i = 0; i < len; i ++) {
            sum += A[i];
        }
        int lmax = 0, rmax = 0, cnt = A[0], maxv = A[0], pos = 0;
        for (int i = 1; i < len; i ++) {
            if (cnt < 0) {
                cnt = 0;
                pos = i;
            }
            cnt += A[i];
            if (cnt > maxv) {
                maxv = cnt;
                lmax = pos;
                rmax = i;
            }
        }
        cnt = A[0], pos = 0;
        int lmin = 0, rmin = 0, minv = A[0];
        for (int i = 1; i < len; i ++) {
            if (cnt > 0) {
                cnt = 0;
                pos = i;
            }
            cnt += A[i];
            if (cnt < minv) {
                minv = cnt;
                lmin = pos;
                rmin = i;
            }
        }
        if (maxv > sum - minv || (rmin - lmin + 1 == len)) { // all nums are negative
            res.push_back(lmax);
            res.push_back(rmax);
        } else {
            if (++rmin == len) rmin = 0;
            if (--lmin < 0) lmin = len - 1;
            res.push_back(rmin);
            res.push_back(lmin);
        }
        return res;
    }
};
