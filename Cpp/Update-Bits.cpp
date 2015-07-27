class Solution {
public:
    /**
     *@param n, m: Two integer
     *@param i, j: Two bit positions
     *return: An integer
     */
    int updateBits(int n, int m, int i, int j) {
        // write your code here
        if (j - i == 31) return m;
        int  res = (1 << (j-i+1)) - 1;
        res = res << i;
        res = ~res;
        res = res & n;
        return res | (m << i);
    }
};
