class Solution{
public:
    /**
     * @param nums: A list of integer which is 0, 1 or 2
     * @return: nothing
     */
    void sortColors(vector<int> &nums) {
        // write your code here
        int left = 0, right = nums.size() - 1;
        while (left < right) {
            while (nums[left] != 2 && left < right) {
                left ++;
            }
            while (nums[right] == 2 && left < right) {
                right --;
            }
            if (left < right) {
                int cnt = nums[left];
                nums[left] =nums[right];
                nums[right] = cnt;
            }
        }
        right = left - 1,left = 0;
        while (left < right) {
            while (nums[left] == 0 && left < right) {
                left ++;
            }
            while (nums[right] == 1 && left < right) {
                right --;
            }
            if (left < right) {
                int cnt = nums[left];
                nums[left] =nums[right];
                nums[right] = cnt;
            }
        }
    }
};
