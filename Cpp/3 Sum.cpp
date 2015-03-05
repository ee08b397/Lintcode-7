#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    /**
     * @param numbers : Give an array numbers of n integer
     * @return : Find all unique triplets in the array which gives the sum of zero.
     */
    vector<vector<int> > threeSum(vector<int> &nums) {
        // write your code here
        sort(nums.begin(), nums.end());
        vector<vector<int> > vec;
        for (int i = 0; i + 2 < nums.size(); i++) {
            if (i > 0 && nums[i-1] == nums[i]) continue;
            int left = i + 1, right = nums.size() - 1;
            while (left < right) {
                int s = nums[left] + nums[right] + nums[i];
                if (s == 0) {
                    vector<int> res;
                    res.push_back(nums[i]);
                    res.push_back(nums[left]);
                    res.push_back(nums[right]);
                    vec.push_back(res);
                    left++;
                    right--;
                    while (left < right && nums[left] == nums[left-1]) {
                        left ++;
                    }
                    while (left < right && nums[right] == nums[right+1]) {
                        right --;
                    }
                } else if (s < 0) {
                    left++;
                } else {
                    right--;
                }
            }
        }
        return vec;
    }
};

