public class Solution {
    /**
     * @param candidates: A list of integers
     * @param target:An integer
     * @return: A list of lists of integers
     */
    public void helper(List<List<Integer>> res, List<Integer> cur, int target, int[] candidates, int index) {
        if (target == 0) {
            res.add(new ArrayList<Integer>(cur));
            return;
        }
        int prev = -1;
        for (int i = index; i < candidates.length; i ++) {
            if (candidates[i] > target) break;
            if (prev != -1 && prev == candidates[i])
                continue;
            cur.add(candidates[i]);
            helper(res, cur, target - candidates[i], candidates, i);
            cur.remove(cur.size() - 1);
            prev = candidates[i];
        }
    }
    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        // write your code here
        List<List<Integer>> res = new ArrayList<List<Integer>>();
        if (candidates == null) return res;
        List<Integer> cur = new ArrayList<Integer>();
        Arrays.sort(candidates);
        helper(res, cur, target, candidates, 0);
        return res;
    }
}



