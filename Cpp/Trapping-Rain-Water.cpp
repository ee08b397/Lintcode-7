#include <vector>

class Solution {
public:
    /**
     * @param heights: a vector of integers
     * @return: a integer
     */
    int trapRainWater(vector<int> &heights) {
        // write your code here
        int maxh = 0;
        for (int i = 0; i < heights.size(); i ++) {
            if (heights[i] > heights[maxh]) maxh = i;
        }
        int water = 0;
        for (int i = 0, peak = 0; i < maxh; i ++) {
            if (heights[i] > peak) peak = heights[i];
            else water += peak - heights[i];
        }
        for (int i = heights.size() - 1, top = 0; i > maxh; i --) {
            if (heights[i] > top) top = heights[i];
            else water += top - heights[i];
        }
        return water;
    }
};
