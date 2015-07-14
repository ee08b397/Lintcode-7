public class Solution {
    /**
     * @param A an integer array
     * @return  A list of integers includes the index of the first number and the index of the last number
     */
    public ArrayList<Integer> continuousSubarraySumII(int[] A) {
        // Write your code here
        int leftm = 0, rightm = 0, cur = -1, maxv = Integer.MIN_VALUE, sum = 0, pos = 0;
        for (int i = 0; i < A.length; i ++) {
            sum += A[i];
            if (cur < 0) {
                pos = i;
                cur = A[i];
            } else {
                cur += A[i];
            }
            if (cur > maxv) {
                maxv = cur;
                leftm = pos;
                rightm = i;
            }
        }
        int leftmin = 0, rightmin = 0, minv = Integer.MAX_VALUE;
        pos = 0;
        cur = 1;
        for (int i = 0; i < A.length; i ++) {
            if (cur > 0) {
                pos = i;
                cur = A[i];
            } else {
                cur += A[i];
            }
            if (cur < minv) {
                minv = cur;
                leftmin = pos;
                rightmin = i;
            }
        }
        ArrayList<Integer> res = new ArrayList<Integer>();
        if (maxv > sum - minv || (rightmin - leftmin + 1 == A.length)) {
            res.add(leftm);
            res.add(rightm);
        } else {
            rightmin ++;
            leftmin --;
            if (rightmin == A.length) rightmin = 0;
            if (leftmin < 0) leftmin = A.length - 1;
            res.add(rightmin);
            res.add(leftmin);
        }
        return res;
    }
}