#include <vector>

class Solution {
public:
    /**
     * @param ratings Children's ratings
     * @return the minimum candies you must give
     */
    int candy(vector<int>& ratings) {
        // Write your code here
        int len = ratings.size();
        vector<int> nums(len, 1);
        nums[0] = 1;
        for (int i = 0; i < len - 1; i ++) {
            if (ratings[i + 1] > ratings[i]) nums[i + 1] = nums[i] + 1;
        }
        for (int i = len - 1; i > 0; i --) {
            if (ratings[i-1] > ratings[i]) nums[i-1] = max(nums[i-1], nums[i] + 1);
        }
        int sum = 0;
        for (int i = 0; i < len; i ++) {
            sum += nums[i];
        }
        return sum;
    }
};
