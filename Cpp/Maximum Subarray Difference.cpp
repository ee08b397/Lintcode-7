#include <vector>

class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: An integer indicate the value of maximum difference between two
     *          Subarrays
     */
    int abs(int s) {
        if (s < 0) return -s;
        else return s;
    }
    int maxDiffSubArrays(vector<int> nums) {
        // write your code here
        int len = nums.size();
        vector<int> leftmin(len), leftmax(len), rightmin(len), rightmax(len);
        int res1 = nums[0], cnt1 = 0, res2 = nums[0], cnt2 = 0;
        for (int i = 0; i < len; i ++) {
            cnt1 = max(cnt1 + nums[i], nums[i]);
            cnt2 = min(cnt2 + nums[i], nums[i]);
            res1 = max(cnt1, res1);
            res2 = min(cnt2, res2);
            leftmax[i] = res1;
            leftmin[i] = res2;
        }
        res1 = nums[len-1], cnt1 = 0, res2 = nums[len-1], cnt2 = 0;
        for (int i = len - 1; i >= 0; i --) {
            cnt1 = max(cnt1 + nums[i], nums[i]);
            cnt2 = min(cnt2 + nums[i], nums[i]);
            res1 = max(cnt1, res1);
            res2 = min(cnt2, res2);
            rightmax[i] = res1;
            rightmin[i] = res2;
        }
        int maxdiffsub = 0;
        for (int i = 0; i < len - 1; i ++) {
            maxdiffsub = max(maxdiffsub, max(abs(leftmax[i] - rightmin[i+1]), abs(rightmax[i+1] - leftmin[i])));
        }
        return maxdiffsub;
    }
};

