public class Solution {
    /**
     * @param A an integer array
     * @return  A list of integers includes the index of the first number and the index of the last number
     */
    public ArrayList<Integer> continuousSubarraySum(int[] A) {
        // Write your code here
        ArrayList<Integer> res = new ArrayList<Integer>();
        int cur = -1, maxv = Integer.MIN_VALUE, left = 0, right = 0, pos = 0;
        for (int i = 0; i < A.length; i ++) {
            if (cur < 0) {
                pos = i;
                cur = A[i];
            } else {
                cur += A[i];
            }
            if (cur > maxv) {
                maxv = cur;
                left = pos;
                right = i;
            }
        }
        res.add(left);
        res.add(right);
        return res;
    }
}
