#include <vector>

using namespace std;

class Solution {
public:
    /**
     * @param numbers: Give an array numbers of n integer
     * @param target: An integer
     * @return: return the sum of the three integers, the sum closest target.
     */
    int abs(int cnt) {
        if (cnt >= 0) return cnt;
        else return cnt * -1;
    }
    int threeSumClosest(vector<int> nums, int target) {
        // write your code here
        sort(nums.begin(), nums.end());
        int res = nums[0] + nums[1] + nums[2];
        for (int i = 0; i + 2 < nums.size(); i++) {
            int left = i + 1, right = nums.size() - 1;
            while (left < right) {
                int s = nums[i] + nums[left] + nums[right];
                if (abs(s - target) < abs(res - target)) res = s;
                if (s == target) return s;
                else if (s < target) left ++;
                else right --;
            }
        }
        return res;
    }
};

