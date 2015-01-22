#include <vector>

class Solution {
public:
    /**
     * @param prices: Given an integer array
     * @return: Maximum profit
     */
    int maxProfit(vector<int> &prices) {
        // write your code here
        int len = prices.size();
        if (len <= 1) return 0;
        int cur = prices[0], maxp = 0;
        for (int i = 1; i < len; i++) {
            cur = min(cur, prices[i]);
            maxp = max(maxp, prices[i] - cur);
        }
        return maxp;
    }
};

