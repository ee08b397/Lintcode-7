class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: A list of integers includes the index of the first number
     *          and the index of the last number
     */
    vector<int> subarraySum(vector<int> nums){
        // write your code here
        int len = nums.size();
        map<int, int> mp;
        mp[0] = -1;
        vector<int> vec;
        int sum = 0;
        for (int i = 0; i < len; i ++) {
            sum += nums[i];
            if (mp.find(sum) == mp.end()) {
                mp[sum] = i;
            } else {
                vec.push_back(mp[sum]+1);
                vec.push_back(i);
                return vec;
            }
        }
        return vec;
    }
};
