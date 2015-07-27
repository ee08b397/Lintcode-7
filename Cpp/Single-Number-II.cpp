class Solution {
public:
    /**
     * @param A : An integer array
     * @return : An integer
     */
    int singleNumberII(vector<int> &A) {
        // write your code here
        int res = 0;
        for (int i = 0; i < 32; i ++) {
            int cnt = 0, s = 1 << i;
            for (int j = 0; j < A.size(); j ++) {
                if (A[j] & s) cnt ++;
            }
            if (cnt % 3) res |= s;
        }
        return res;
    }
};
