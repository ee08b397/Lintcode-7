public class Solution {
    /**
     * @param n: An integer.
     * return : An array storing 1 to the largest number with n digits.
     */
    public void helper(int start, int end, List<Integer> res){
        for (int i = start; i < end; i ++) {
            res.add(i);
        }
    }
    public List<Integer> numbersByRecursion(int n) {
        // write your code here
        List<Integer> res = new ArrayList<Integer>();// 使用linkedlist会超时
        if (n <= 0) return res;
        int cur = 1;
        for (int i = 1; i <= n; i ++) {
            //helper(cur, cur * 10, res);
            for (int j = cur; j < cur * 10; j ++) {
                res.add(j);
            }
            cur = cur * 10;
        }
        return res;
    }
}