#include <vector>
#include <map>

class Solution {
public:
    /*
     * @param numbers : An array of Integer
     * @param target : target = numbers[index1] + numbers[index2]
     * @return : [index1+1, index2+1] (index1 < index2)
     */
    vector<int> twoSum(vector<int> &nums, int target) {
        // write your code here
        map<int, int> st;
        for (int i = 0; i < nums.size(); i++) {
            st[nums[i]] = i;
        }
        vector<int> vec;
        for (int i = 0; i < nums.size(); i++) {
            int cnt = target - nums[i];
            if (st.find(cnt) != st.end()) {
                vec.push_back(i+1);
                vec.push_back(st[cnt]+1);
                return vec;
            }
        }
    }
};

