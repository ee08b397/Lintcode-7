class Solution {
public:
    /**
     * @param A: a list of integers
     * @return : return an integer
     */
    int removeDuplicates(vector<int> &nums) {
        // write your code here
        if (nums.size() <= 2) return nums.size();
        int index = 0, res = 1;
        for (int i = 1; i < nums.size(); i ++) {
            if (nums[i] != nums[index]) {
                nums[++index] = nums[i];
                res = 1;
            } else {
                if (res < 2) {
                    res += 1;
                    nums[++index] = nums[i];
                }
            }
        }
        return index + 1;
    }
};
