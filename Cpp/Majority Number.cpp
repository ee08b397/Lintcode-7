class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: The majority number
     */
    int majorityNumber(vector<int> nums) {
        // write your code here
        int cnt = 1, res = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (cnt == 0) {
                res = nums[i];
                cnt = 1;
            }
            if (nums[i] == res) {
                cnt ++;
            } else {
                cnt --;
            }
        }
        return res;
    }
};
