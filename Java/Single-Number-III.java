public class Solution {
    /**
     * @param A : An integer array
     * @return : Two integers
     */
    public List<Integer> singleNumberIII(int[] A) {
        // write your code here
        int cur = 0;
        for (int i = 0; i < A.length; i ++) {
            cur ^= A[i];
        }
        int res = cur & ~(cur - 1);
        int x = 0, y = 0;
        for (int i = 0; i < A.length; i ++) {
            if ((A[i] & res) == 0) x ^= A[i];
            else y ^= A[i];
        }
        List<Integer> result = new LinkedList<Integer>();
        result.add(x);
        result.add(y);
        return result;
    }
}
