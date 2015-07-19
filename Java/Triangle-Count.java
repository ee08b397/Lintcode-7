public class Solution {
    /**
     * @param S: A list of integers
     * @return: An integer
     */
    public int triangleCount(int S[]) {
        // write your code here
        Arrays.sort(S);
        int res = 0;
        for (int i = S.length - 1; i - 2 >= 0; i --) {
            int left = 0, right = i - 1;
            while (left < right) {
                int temp = S[left] + S[right];
                if (temp <= S[i]) {
                    left ++;
                } else {
                    res += (right - left);
                    right --;
                }
            }
        }
        return res;
    }
}