public class Solution {
    /**
     * @param S: A set of numbers.
     * @return: A list of lists. All valid subsets.
     */
    public void helper(ArrayList<ArrayList<Integer>> res, ArrayList<Integer> cur, int index, ArrayList<Integer> S) {
        res.add(new ArrayList<Integer>(cur));
        for (int i = index; i < S.size(); i ++) {
            cur.add(S.get(i));
            helper(res, cur, i + 1, S);
            cur.remove(cur.size() - 1);
        }
    }
    public ArrayList<ArrayList<Integer>> subsets(ArrayList<Integer> S) {
        // write your code here
        ArrayList<ArrayList<Integer>> res = new ArrayList<ArrayList<Integer>>();
        if (S == null || S.size() == 0) return res;
        ArrayList<Integer> cur = new ArrayList<Integer>();
        Collections.sort(S);
        helper(res, cur, 0, S);
        return res;
    }
}
