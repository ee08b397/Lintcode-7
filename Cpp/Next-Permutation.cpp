#include <vector>
#include <algorithm>

class Solution {
public:
    /**
     * @param nums: An array of integers
     * @return: An array of integers that's next permuation
     */
    vector<int> nextPermuation(vector<int> &nums) {
        // write your code here
        next_permutation(nums.begin(), nums.end());
        return nums;
    }
};
