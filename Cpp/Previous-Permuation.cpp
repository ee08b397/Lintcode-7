#include <vector>
#include <algorithm>

class Solution {
public:
    /**
     * @param nums: An array of integers
     * @return: An array of integers that's previous permuation
     */
    vector<int> previousPermuation(vector<int> &nums) {
        // write your code here
        //sort(nums.begin(), nums.end());
        prev_permutation(nums.begin(), nums.end());
        return nums;
    }
};
