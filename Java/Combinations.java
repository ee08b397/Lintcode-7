public class Solution {
    /**
     * @param n: Given the range of numbers
     * @param k: Given the numbers of combinations
     * @return: All the combinations of k numbers out of 1..n
     */
    public void helper(List<List<Integer>> res, List<Integer> cur, int num, int pos, int end) {
        if (num == 0) {
            res.add(new ArrayList<Integer>(cur));
            return;
        }
        for (int i = pos; i <= end; i ++){
            cur.add(i);
            helper(res, cur, num - 1, i + 1, end);
            cur.remove(cur.size() - 1);
        }
    }
    public List<List<Integer>> combine(int n, int k) {
        // write your code here
        List<List<Integer>> res = new ArrayList<List<Integer>>();
        List<Integer> cur = new ArrayList<Integer>();
        if (k > n || n <= 0) return res;
        helper(res, cur, k, 1, n);
        return res;
    }
}
