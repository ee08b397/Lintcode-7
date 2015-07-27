#include <vector>

class Solution {
public:
    /**
     * @param nums: a vector of integers
     * @return: nothing
     */
    void partitionArray(vector<int> &nums) {
        // write your code here
        if (nums.empty()) return;
        int left = 0, right = nums.size() - 1;
        while (left < right) {
            while (nums[left] % 2 == 1) left ++;
            while (nums[right] % 2 == 0) right --;
            if (left < right) {
                int temp = nums[left];
                nums[left] = nums[right];
                nums[right] = temp;
                left ++;
                right --;
            }
        }
        return;
    }
};
