class Solution {
public:
    int partitionArray(vector<int> &nums, int k) {
        // write your code here
        int left = 0, right = nums.size() - 1;
        while (left < right) {
            while (nums[left] < k && left < right) {
                left ++;
            }
            while (nums[right] >= k && left < right) {
                right --;
            }
            if (left < right) {
                int cnt = nums[left];
                nums[left] = nums[right];
                nums[right] = cnt;
            }
        }
        int res = nums.size();
        for (int i = 0; i < nums.size(); i ++) {
            if (nums[i] > k) return i;
        }
        return res;
    }
};
