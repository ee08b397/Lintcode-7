public class Solution {
    /**
     * @param A an integer array
     * @return a long integer
     */
    public long factor(long n) {
        if (n <= 1) return 1;
        long res = 1;
        for (long i = 2; i <= n; i ++) {
            res *= i;
        }
        return res;
    }
    public int findrank(int[] dup, HashSet<Integer> hash, int num) {
        int cur = 0;
        for (int i = 0; i < dup.length; i ++) {
            if (dup[i] == num) return cur;
            else if (!hash.contains(dup[i])) cur ++;
        }
        return cur;
    }
    public long permutationIndex(int[] A) {
        // Write your code here
        int len = A.length;
        int[] dup = new int[len];
        for (int i = 0; i < len; i ++) {
            dup[i] = A[i];
        }
        Arrays.sort(dup);
        HashSet<Integer> hash = new HashSet<Integer>();
        long res = 1;
        for (int i = 0; i < len; i ++) {
            int rank = findrank(dup, hash, A[i]);
            res = res + rank * factor(len - i - 1);
            hash.add(A[i]);
        }
        return res;
    }
}
