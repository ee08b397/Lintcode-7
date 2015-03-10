class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: A integer indicate the sum of max subarray
     */
    int maxSubArray(vector<int> nums) {
        // write your code here
        if (nums.size() == 0) return 0;
        int res = nums[0], cnt = 0;
        for (int i = 0; i < nums.size(); i ++) {
            cnt = max(cnt + nums[i], nums[i]);
            res = max(res, cnt);
        }
        return res;
    }
};
