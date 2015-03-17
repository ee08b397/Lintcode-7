class Solution {
public:
    /**
     * @param n: Given the range of numbers
     * @param k: Given the numbers of combinations
     * @return: All the combinations of k numbers out of 1..n
     */
    void solve(vector<vector<int> >&vec, vector<int> &res, int cnt, int end, int k, int num) {
        if (num == k) {
            vec.push_back(res);
            return;
        }
        if (cnt > end) {
            return;
        }
        res.push_back(cnt);
        solve(vec, res, cnt+1, end, k, num+1);
        res.pop_back();
        solve(vec, res, cnt+1, end, k, num);
    }
    vector<vector<int> > combine(int n, int k) {
        // write your code here
        vector<vector<int> > vec;
        if (n == 0) return vec;
        vector<int> res;
        solve(vec, res, 1, n, k, 0);
        return vec;
    }
};
