class Solution {
public:
    /**
     * @param S: A set of numbers.
     * @return: A list of lists. All valid subsets.
     */
    void solve(vector<vector<int> >&vec, vector<int> &res, vector<int> &nums, int start) {
        if (start == nums.size()) {
            vec.push_back(res);
            return;
        }
        res.push_back(nums[start]);
        solve(vec, res, nums, start+1);
        res.pop_back();
        solve(vec, res, nums, start+1);
    }
    vector<vector<int> > subsets(vector<int> &nums) {
        // write your code here
        sort(nums.begin(), nums.end());
        vector<vector<int> > vec;
        vector<int> res;
        solve(vec, res, nums, 0);
        return vec;
    }
};
