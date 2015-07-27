#include <vector>

class Solution {
public:
    /**
     * @param heights: a vector of integers
     * @return: an integer
     */
    int maxArea(vector<int> &heights) {
        // write your code here
        if (heights.empty()) return 0;
        int maxArea = 0;
        int left = 0, right = heights.size() - 1;
        while (left < right) {
            maxArea = max((right - left) * min(heights[right], heights[left]), maxArea);
            if (heights[left] < heights[right]) left ++;
            else right --;
        }
        return maxArea;
    }
};
