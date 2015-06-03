#include <vector>

class Solution {
public:
    int maximumGap(vector<int> &nums) {
        if (nums.size() < 2) return 0;
        //遍历一遍，找出最大最小值
        int maxNum = nums[0];
        int minNum = nums[0];
        for (int i : nums) {
            maxNum=max(maxNum,i);
            minNum=min(minNum,i);
        }
        // 每个桶的长度len,向上取整所以加+
        int len = (maxNum - minNum) / nums.size() + 1;

        //桶的个数:(maxNum - minNum) / len + 1,每个桶里面存储属于该桶的最大值和最小值即可，注意这里的最大最小值是局部的
        vector<vector<int> > buckets((maxNum - minNum) / len + 1);
        for (int x : nums) {
            int i = (x - minNum) / len;
            if (buckets[i].empty()) {
                buckets[i].reserve(2);
                buckets[i].push_back(x);
                buckets[i].push_back(x);
            } else {
                if (x < buckets[i][0]) buckets[i][0] = x;
                if (x > buckets[i][1]) buckets[i][1] = x;
            }
        }
        //gap的计算，For each non-empty buckets p, find the next non-empty buckets q, return min（ q.min - p.max ）
        int gap = 0;
        int prev = 0;
        for (int i = 1; i < buckets.size(); i++) {
            if (buckets[i].empty()) continue;
            gap = max(gap, buckets[i][0] - buckets[prev][1]);
            prev = i;
        }
        return gap;
    }
};