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
        int sum = 0, len = prices.size();
        int cur = prices[0];
        for (int i = 1; i < len; i++) {
            if (prices[i] < cur) {
                cur = prices[i];
            } else {
                sum += (prices[i] - cur);
                cur = prices[i];
            }
        }
        return sum;
    }
};