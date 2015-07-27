#include <vector>

class Solution {
public:
    /**
     * @param prices: Given an integer array
     * @return: Maximum profit
     */
    int maxProfit(vector<int> &prices) {
        // write your code here
        if (prices.size() <= 1) return 0;
        int len = prices.size(), minp;
        vector<int> left(len), right(len);
        left[0] = 0, minp = prices[0];
        for (int i = 1; i < len; i ++) {
            left[i] = max(prices[i] - minp, left[i-1]);
            minp = min(minp, prices[i]);
        }
        right[len-1] = 0, minp = prices[len-1];
        for (int i = len - 2; i >= 0; i --) {
            right[i] = max(minp - prices[i], right[i+1]);
            minp = max(minp, prices[i]);
        }
        int maxP = 0;
        for (int i = 0; i < len; i ++) {
            maxP = max(maxP, left[i] + right[i]);
        }
        return maxP;
    }
};
