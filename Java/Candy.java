public class Solution {
    /**
     * @param ratings Children's ratings
     * @return the minimum candies you must give
     */
    public int candy(int[] ratings) {
        // Write your code here
        int[] res = new int[ratings.length];
        res[0] = 1;
        for (int i = 1; i < ratings.length; i ++) {
            if (ratings[i] > ratings[i - 1]) res[i] = res[i - 1] + 1;
            else res[i] = 1;
        }
        for (int i = ratings.length - 1; i >= 1; i --) {
            if (ratings[i - 1] > ratings[i]) res[i- 1] = Math.max(res[i] + 1, res[i- 1]);
        }
        int result = 0;
        for (int i = 0; i < res.length; i ++) {
            result += res[i];
        }
        return result;
    }
}
