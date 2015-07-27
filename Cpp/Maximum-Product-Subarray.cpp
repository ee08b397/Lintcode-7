#include <vector>

class Solution {
public:
    /**
     * @param nums: a vector of integers
     * @return: an integer
     */
    int maxProduct(vector<int>& nums) {
        // write your code here
        int minp = nums[0], maxp = nums[0], cnt = nums[0];
        int x, y, z;
        for (int i = 1; i < nums.size(); i ++) {
            x = nums[i] * minp;
            y = nums[i] * maxp;
            z = nums[i];
            minp = min(min(x, y), z);
            maxp = max(max(x, y), z);
            if (maxp > cnt) cnt = maxp;
        }
        return cnt;
    }
};
