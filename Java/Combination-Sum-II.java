public class Solution {
    /**
     * @param num: Given the candidate numbers
     * @param target: Given the target number
     * @return: All the combinations that sum to target
     */
    public void helper(List<List<Integer>> res, List<Integer> cur, int[] num, int target, int pos) {
        if (target == 0) {
            res.add(new ArrayList<Integer>(cur));
            return;
        }
        int pre = -1;
        for (int i = pos; i < num.length; i ++) {
            if (pre != -1 && pre == num[i]) continue;
            pre = num[i];
            if (num[i] > target) return;
            cur.add(num[i]);
            helper(res, cur, num, target - num[i], i + 1);
            cur.remove(cur.size() - 1);
        }
    }
    public List<List<Integer>> combinationSum2(int[] num, int target) {
        // write your code here
        Arrays.sort(num);
        List<List<Integer>> res = new ArrayList<List<Integer>>();
        if (num == null && num.length == 0) return res;
        List<Integer> cur = new ArrayList<Integer>();
        helper(res, cur, num, target, 0);
        return res;
    }
}
