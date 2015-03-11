class Solution {
public:
    /**
     * @param S, T: Two string.
     * @return: Count the number of distinct subsequences
     */
    int numDistinct(string &S, string &T) {
        // write your code here
        int lens = S.size(), lent = T.size();
        vector<vector<int> >vec(lens+1, vector<int>(lent+1));
        for (int i = 0; i <= lens; i ++) {
            for (int j = 0; j <= lent; j ++) {
                if (i < j) vec[i][j] = 0;
                else if (i == 0 || j == 0) vec[i][j] = 1;
                else if (S[i-1] == T[j-1]) vec[i][j] = vec[i-1][j] + vec[i-1][j-1];
                else vec[i][j] = vec[i-1][j];
            }
        }
        return vec[lens][lent];
    }
};
