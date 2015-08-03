public class Solution {
    /**
     * @param A: Given an integers array A
     * @return: A Long array B and B[i]= A[0] * ... * A[i-1] * A[i+1] * ... * A[n-1]
     */
    public ArrayList<Long> productExcludeItself(ArrayList<Integer> A) {
        // write your code
        int len = A.size();
        ArrayList<Long> res = new ArrayList<Long>();
        for (int i = 0; i < len; i ++) {
            res.add((long) 1);
        }
        long cur = 1;
        for (int i = 1; i < len; i ++) {
            res.set(i, A.get(i - 1) * res.get(i - 1));
        }
        for (int i = len - 2; i >= 0; i --) {
            cur = cur * A.get(i + 1);
            res.set(i, res.get(i) * cur);
        }
        return res;
    }
}
