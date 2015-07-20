class Solution {
    /**
     *@param n, m: Two integer
     *@param i, j: Two bit positions
     *return: An integer
     */
    public int updateBits(int n, int m, int i, int j) {
        // write your code here
        if (j - i == 31) return m;
        int cur = (1 << (j - i + 1)) - 1;
        cur = cur << i;
        cur = ~cur;
        cur = cur & n;
        return cur | (m << i);
    }
}