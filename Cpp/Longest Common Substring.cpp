class Solution {
public:
    /**
     * @param A, B: Two string.
     * @return: the length of the longest common substring.
     */
    int longestCommonSubstring(string &A, string &B) {
        // write your code here
        int lenA = A.size(), lenB = B.size();
        vector<vector<int> > vec(lenA+1, vector<int>(lenB+1));
        vec[0][0] = 0;
        int res = 0;
        for (int i = 0; i < lenA; i ++) {
            for (int j = 0; j < lenB; j ++) {
                if (A[i] == B[j]) {
                    vec[i+1][j+1] = vec[i][j] + 1;
                    res = max(vec[i+1][j+1], res);
                }
            }
        }
        return res;
    }
};
