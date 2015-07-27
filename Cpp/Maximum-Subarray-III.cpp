#include <vector>

class Solution {
public:
    /**
     * @param nums: A list of integers
     * @param k: An integer denote to find k non-overlapping subarrays
     * @return: An integer denote the sum of max k non-overlapping subarrays
     */
    int maxSubArray(vector<int> nums, int k) {
        // write your code here
        int len = nums.size();
        vector<vector<int> > dp(k + 1, vector<int> (len + 1));
        int cnt = 0, res = 0;
    }
};

