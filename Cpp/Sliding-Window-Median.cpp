class Solution {
public:
    /**
     * @param nums: A list of integers.
     * @return: The median of the element inside the window at each moving
     */
    vector<int> medianSlidingWindow(vector<int> &nums, int k) {
        // write your code here
        vector<int> result;
        int n = nums.size();
        if (n == 0)
            return result;

        multiset<int> max, min;
        for (int i = 0; i < k; ++i)
            max.insert(nums[i]);

        for (int i = 0; i < k/2; ++i) {
            min.insert(*max.rbegin());
            max.erase(max.lower_bound(*max.rbegin()));
        }

        for (int i = k; i < n; ++i) {
            result.push_back(*max.rbegin());
            if (max.find(nums[i-k]) != max.end()) {
                max.erase(max.find(nums[i-k]));
                max.insert(nums[i]);
            } else {
                min.erase(min.find(nums[i-k]));
                min.insert(nums[i]);
            }
            if (max.size() > 0 && min.size() > 0 && *max.rbegin() > *min.begin()) {
                int tmp = *max.rbegin();
                max.erase(max.lower_bound(*max.rbegin()));
                max.insert(*min.begin());
                min.erase(min.begin());
                min.insert(tmp);
            }
        }
        result.push_back(*max.rbegin());

        return result;
    }
};