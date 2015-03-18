class Solution {
public:
    /*
     * param k : As description.
     * param n : As description.
     * return: How many k's between 0 and n.
     */
    int digitCounts(int k, int n) {
        // write your code here
        vector<int> vis(10);
        int res = 0;
        for (int i = 0; i <= n; i ++) {
            int temp = i;
            while (temp != 0) {
                if (temp % 10 == k) {
                    res++;
                }
                temp = temp / 10;
            }
        }
        return res;
    }
};
