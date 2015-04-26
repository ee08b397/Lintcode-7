#include <vector>

class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: An integer denotes the sum of max two non-overlapping subarrays
     */
    int maxTwoSubArrays(vector<int> nums) {
        // write your code here
        int len = nums.size(), res, cnt;
        vector<int> left(len), right(len);
        left[0] = nums[0], res = nums[0], cnt = 0;
        for (int i = 0; i < len; i ++) {
            cnt = max(cnt + nums[i], nums[i]);
            res = max(res, cnt);
            left[i] = res;
        }
        right[len-1] = nums[len-1], res = nums[len-1], cnt = 0;
        for (int i = len - 1; i >= 0; i --) {
            cnt = max(cnt + nums[i], nums[i]);
            res = max(res, cnt);
            right[i] = res;
        }
        int maxsub = INT_MIN;
        for (int i = 0; i < len - 1; i ++) {
            maxsub = max(maxsub, left[i] + right[i+1]);
        }
        return maxsub;
    }
};

