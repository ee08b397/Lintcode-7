public class Solution {
    /**
     * @param A: An integer array
     * @return: Count the number of element before this element 'ai' is
     *          smaller than it and return count number array
     */
    public int lowbit(int n) {
        return n & (-n);
    }
    public int helper(int[] c, int n) {
        int res = 0;
        while (n > 0) {
            res += c[n];
            n -= lowbit(n);
        }
        return res;
    }
    public void add(int[] c, int i, int x) {
        while (i < c.length) {
            c[i] += x;
            i += lowbit(i);
        }
    }
    public ArrayList<Integer> countOfSmallerNumberII(int[] A) {
        // write your code here
        ArrayList<Integer> res = new ArrayList<Integer>();
        int[] c = new int[10002];
        for (int i = 0; i < A.length; i ++) {
            res.add(helper(c, A[i]));
            add(c, A[i] + 1, 1);
        }
        return res;
    }
}
