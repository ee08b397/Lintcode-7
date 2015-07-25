class Solution {
    /**
     * @param n: n
     * @param k: the kth permutation
     * @return: return the k-th permutation
     */
    public int factor(int n) {
        if (n <= 1) return 1;
        int res = 1;
        for (int i = 2; i <= n; i ++) {
            res *= i;
        }
        return res;
    }
    public int select(int[] used, int pos) {
        int cur = 0;
        for (int i = 0; i < used.length; i ++) {
            if (used[i] == 0) {
                if (pos == cur) return i + 1;
                cur ++;
            }
        }
        return used.length;
    }
    public String getPermutation(int n, int k) {
        int[] used = new int[n];
        Arrays.fill(used, 0);
        StringBuffer sb = new StringBuffer();
        int cur = 1;
        while (k > 1) {
            int temp = factor(n - cur);
            int pos = k / temp;
            if (k % temp == 0) {
                pos --;
            }
            int num = select(used, pos);
            cur ++;
            sb.append(String.valueOf(num));
            used[num - 1] = 1;
            k = k - temp * pos;
        }
        for (int i = 0; i < n; i ++) {
            if (used[i] == 0) sb.append(String.valueOf(i + 1));
        }
        return sb.toString();
    }
}

