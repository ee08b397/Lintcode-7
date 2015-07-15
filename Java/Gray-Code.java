public class Solution {
    /**
     * @param n a number
     * @return Gray code
     */
    public ArrayList<Integer> grayCode(int n) {
        // Write your code here
        ArrayList<Integer> res = new ArrayList<Integer>();
        int m = 1 << n;
        for (int i = 0; i < m; i ++) {
            res.add(i ^ (i >> 1));
        }
        return res;
    }
}