class Solution {
public:
    /**
     * @param nums: The integer array
     * @return: The length of LIS (longest increasing subsequence)
     */
    int longestIncreasingSubsequence(vector<int> nums) {
        // write your code here
        vector<int> vec(nums.size(), 1);
        for (int i = 1; i < nums.size(); i ++) {
            for (int j = 0; j < i; j ++) {
                if (nums[i] >= nums[j]) {
                    vec[i] = max(vec[i], vec[j]+1);
                }
            }
        }
        int cnt = 0;
        for (int i = 0; i < vec.size(); i ++) {
            cnt = max(cnt, vec[i]);
        }
        return cnt;
    }
};
