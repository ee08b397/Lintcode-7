#include <vector>
#include <algorithm>

class Solution {
public:
    /**
     * @param A: an integer array.
     * @param k: a positive integer (k <= length(A))
     * @param target: a integer
     * @return a list of lists of integer
     */
    void solve(vector<vector<int> > &res, vector<int> &A,vector<int> &cnt, int pos, int num ,int k, int target) {
        if (target == 0 && num == k) {
            res.push_back(cnt);
        }
        if (target < 0 || pos >= A.size() || num >= k) return;
        cnt.push_back(A[pos]);
        solve(res, A, cnt, pos + 1, num + 1, k, target - A[pos]);
        cnt.pop_back();
        solve(res, A, cnt, pos + 1, num, k, target);
    }
    vector<vector<int> > kSumII(vector<int> A, int k, int target) {
        // write your code here
        sort(A.begin(), A.end());
        vector<int> cnt;
        vector<vector<int> > res;
        solve(res, A, cnt, 0, 0, k, target);
        return res;
    }
};

