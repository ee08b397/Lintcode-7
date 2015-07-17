class Solution {
public:
    void reverse(vector<int> &nums, int start, int end) {
        int mid = (end - start + 1) / 2 + start;
        for (int i = start; i < mid; i ++) {
            int cnt = nums[i];
            nums[i] = nums[end - (i - start)];
            nums[end - (i - start)] = cnt;
        }
    }
    void recoverRotatedSortedArray(vector<int> &nums) {
        // write your code here
        int pos = -1;
        for (int i = 0; i < nums.size() - 1; i ++) {
            if (nums[i] > nums[i+1]) {
                pos = i;
                break;
            }
        }
        if (pos == -1) return;
        reverse(nums, 0, pos);
        reverse(nums, pos+1, nums.size()-1);
        reverse(nums, 0, nums.size()-1);
    }
};
