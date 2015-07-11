public class Solution {
    /**
     * @param A : An integer array
     * @return : An integer
     */
    public int singleNumberII(int[] A) {
        // write your code here
        int cur = 1, res = 0;
        for (int i = 0; i < 32; i ++) {
            int cnt = 0, temp = cur << i;
            for (int j = 0; j < A.length; j ++) {
                if ((A[j] & temp) != 0) cnt ++;
            }
            if (cnt % 3 == 1) res = res | (1 << i);
        }
        return res;
    }
}
