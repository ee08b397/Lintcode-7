class Solution {
public:
    /**
     * @param m: An integer m denotes the size of a backpack
     * @param A & V: Given n items with size A[i] and value V[i]
     * @return: The maximum value
     */
    int backPackII(int m, vector<int> A, vector<int> V) {
        // write your code here
        int n = A.size();
        vector<int> vec(m+1);
        for (int i = 0; i < n; i ++) {
            for (int j = m; j >= 0; j --) {
                if (j >= A[i]) vec[j] = max(vec[j-A[i]] + V[i], vec[j]);
            }
        }
        return vec[m];
    }
};
