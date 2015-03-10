class Solution {
public:
    /**
     * @param nums: a list of integers
     * @return: A integer denote the sum of minimum subarray
     */
    int minSubArray(vector<int> nums) {
        // write your code here
        int cnt = 0, minsum = nums[0];
        for (int i = 0; i < nums.size(); i ++) {
            cnt = min(nums[i], nums[i] + cnt);
            minsum = min(minsum, cnt);
        }
        return minsum;
    }
};
