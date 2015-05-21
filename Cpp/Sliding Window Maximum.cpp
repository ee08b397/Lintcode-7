#include <deque>
#include <vector>

class Solution {
public:
    /**
     * @param nums: A list of integers.
     * @return: The maximum number inside the window at each moving.
     */
    vector<int> maxSlidingWindow(vector<int> &nums, int k) {
        // write your code here
        vector<int> res;
        if (k == 0 || nums.empty()) return res;
        deque<int> deq;
        for (int i = 0; i < k; i ++) {
            while (!deq.empty() && nums[i] >= nums[deq.back()]) {
                deq.pop_back();
            }
            deq.push_back(i);
        }
        int len = nums.size();
        for (int i = k; i < len; i ++) {
            res.push_back(nums[deq.front()]);
            while (!deq.empty() && nums[i] >= nums[deq.back()]) {
                deq.pop_back();
            }
            while (!deq.empty() && deq.front() <= i - k) {
                deq.pop_front();
            }
            deq.push_back(i);
        }
        res.push_back(nums[deq.front()]);
        return res;
    }
};

