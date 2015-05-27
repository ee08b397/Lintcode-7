#include <vector>

class Solution {
public:
    /**
     * @param nums: a vector of integers
     * @param s: an integer
     * @return: an integer representing the minimum size of subarray
     */
    int minimumSize(vector<int> &nums, int s) {
        // write your code here
        int minlen = INT_MAX;
        int start = 0, len = nums.size(), sum = 0;
        for (int i = 0; i < len; i ++) {
            sum += nums[i];
            while (sum >= s) {
                minlen = min(minlen, i - start + 1);
                sum -= nums[start];
                start ++;
            }
        }
        if (minlen != INT_MAX) return minlen;
        else return 0;
    }
};
