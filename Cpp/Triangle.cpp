class Solution {
public:
    /**
     * @param triangle: a list of lists of integers.
     * @return: An integer, minimum path sum.
     */
    int minimumTotal(vector<vector<int> > &triangle) {
        // write your code here
        int len = triangle.size();
        vector <int> vec(len);
        for (int i = 0; i < len; i ++) {
            vec[i] = triangle[len-1][i];
        }
        for (int i = len-2; i >= 0; i --) {
            for (int j = 0; j <= i; j ++) {
                vec[j] = min(vec[j] + triangle[i][j], vec[j+1] + triangle[i][j]);
            }
        }
        return vec[0];
    }
};
