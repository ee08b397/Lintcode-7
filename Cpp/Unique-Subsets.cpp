class Solution {
public:
    /**
     * @param S: A set of numbers.
     * @return: A list of lists. All valid subsets.
     */
    void solve(vector<vector<int> > &vec, vector<int> &num, vector<int> &res, int start) {
        for (int i = start; i < num.size(); i ++) {
            res.push_back(num[i]);
            vec.push_back(res);
            if (i < num.size() - 1) {
                solve(vec, num, res, i+1);
            }
            res.pop_back();
            while (i < num.size() - 1 && num[i] == num[i+1]) {
                i ++;
            }
        }
    }
    vector<vector<int> > subsetsWithDup(const vector<int> &S) {
        // write your code here
        vector<int> cnt(S.begin(), S.end());
        sort(cnt.begin(), cnt.end());
        vector<vector<int> > vec;
        vector<int> res;
        vec.push_back(res);
        //if (cnt.size() == 0) return vec;
        solve(vec, cnt, res, 0);
        return vec;
    }
};
