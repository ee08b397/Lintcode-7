class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: The majority number occurs more than 1/3.
     */
    int majorityNumber(vector<int> nums) {
        // write your code here
        int n1 = 0, n2 = 0, cnt1 = 0, cnt2 = 0;
        int len = nums.size();
        for (int i = 0; i < len; i ++) {
            if (cnt1 != 0 && nums[i] == n1) {
                cnt1 ++;
            } else if (cnt2 != 0 && nums[i] == n2) {
                cnt2 ++;
            } else if (cnt1 == 0) {
                cnt1 = 1;
                n1 = nums[i];
            } else if (cnt2 == 0) {
                cnt2 = 1;
                n2 = nums[i];
            } else {
                cnt1 --;
                cnt2 --;
            }
        }
        cnt1 = 0, cnt2 = 0;
        for (int i = 0; i < len; i ++) {
            if (nums[i] == n1) {
                cnt1 ++;
            } else if (nums[i] == n2) {
                cnt2 ++;
            }
        }
        if (cnt1 < cnt2) return n2;
        else return n1;
    }
};
