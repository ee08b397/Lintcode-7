class Solution {
public:
    /**
     * @param s a string
     * @return an integer
     */
    int minCut(string s) {
        // write your code here
        int len = s.size();
        vector<vector<int> > vec(len, vector<int>(len));
        for (int i = 1; i <= len; i++) {
            for (int j = 0; j + i - 1 < len; j ++) {
                if (i == 1) {
                    vec[j][j] = 1;
                } else {
                    if (s[j] == s[j+i-1] && i <= 3) {
                        vec[j][j+i-1] = 1;
                    } else if (s[j] == s[j+i-1] && vec[j+1][j+i-2] == 1) {
                        vec[j][j+i-1] = 1;
                    }
                }
            }
        }
        vector<int> res(len);
        int inf = 10000000;
        for (int i = 0; i < len; i ++) {
            res[i] = inf;
        }
        res[0] = 0;
        for (int i = 1; i < len; i ++) {
            if (vec[0][i] == 1) {
                res[i] = 0;
                continue;
            }
            for (int j = 1; j <= i; j ++) {
                if (vec[j][i] == 1) {
                    res[i] = min(res[i], res[j-1] + 1);
                }
            }
        }
        return res[len-1];
    }
};
