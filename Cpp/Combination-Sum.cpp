class Solution {
public:
    /**
     * @param candidates: A list of integers
     * @param target:An integer
     * @return: A list of lists of integers
     */
    void solve(vector<vector<int> > &res, vector<int> &candidates, vector<int> &vec,
     int target, int cnt, int pos) {
         if (target == cnt) {
             res.push_back(vec);
             return;
         }
         if (pos >= candidates.size() || cnt > target) return;
         vec.push_back(candidates[pos]);
         solve(res, candidates, vec, target, cnt+candidates[pos], pos);
         vec.pop_back();
         solve(res, candidates, vec, target, cnt, pos+1);
     }
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        // write your code here
        vector<vector<int> > res;
        vector<int> vec;
        sort(candidates.begin(), candidates.end());
        solve(res, candidates, vec, target, 0, 0);
        return res;
    }
};
