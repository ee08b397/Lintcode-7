public class Solution {
    /**
     * @param A: an integer array.
     * @param k: a positive integer (k <= length(A))
     * @param target: a integer
     * @return a list of lists of integer
     */
    public void helper(ArrayList<ArrayList<Integer>> res, ArrayList<Integer> cur, int A[], int pos, int num, int target) {
        if (num == 0 && target == 0) {
            res.add(new ArrayList<Integer>(cur));
            return;
        }
        for (int i = pos; i < A.length; i ++) {
            if (A[i] > target) break;
            cur.add(A[i]);
            helper(res, cur, A, i + 1, num - 1, target - A[i]);
            cur.remove(cur.size() - 1);
        }
    }
    public ArrayList<ArrayList<Integer>> kSumII(int A[], int k, int target) {
        // write your code here
        ArrayList<ArrayList<Integer>> res = new ArrayList<ArrayList<Integer>>();
        if (A == null || A.length <= 0 || k < 0) return res;
        Arrays.sort(A);
        ArrayList<Integer> cur = new ArrayList<Integer>();
        helper(res, cur, A, 0, k, target);
        return res;
    }
}