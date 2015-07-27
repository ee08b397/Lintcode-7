#include <queue>
#include <vector>
#include <algorithm>

class Solution {
public:
    /**
     * @param nums: A list of integers.
     * @return: The median of numbers
     */
    vector<int> medianII(vector<int> &nums) {
        // write your code here
        priority_queue<int> maxHeap;
        priority_queue<int, vector<int>, greater<int> > minHeap;
        vector<int> vec;
        for (int i = 0; i < nums.size(); i ++) {
            if (i & 1) {
                if (nums[i] < maxHeap.top()) {
                    minHeap.push(maxHeap.top());
                    maxHeap.pop();
                    maxHeap.push(nums[i]);
                } else {
                    minHeap.push(nums[i]);
                }
            } else {
                if (maxHeap.empty()) {
                    maxHeap.push(nums[i]);
                } else {
                    if (nums[i] > minHeap.top()) {
                        maxHeap.push(minHeap.top());
                        minHeap.pop();
                        minHeap.push(nums[i]);
                    } else {
                        maxHeap.push(nums[i]);
                    }
                }
            }
            vec.push_back(maxHeap.top());
        }
        return vec;
    }
};

