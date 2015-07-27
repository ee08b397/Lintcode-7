class Solution {
public:
    int majorityNumber(vector<int> nums, int k) {
        unordered_map<int, int> hash;
        for (int i = 0; i < nums.size(); i++) {
            auto it = hash.find(nums[i]);
            if (it == hash.end()) {
                hash[nums[i]] = 1;
                if (hash.size() == k) {
                    for (auto hit = hash.begin(); hit != hash.end();) {
                        if (--(hit->second) == 0) {
                            hit = hash.erase(hit);
                        }
                        else {
                            hit++;
                        }
                    }
                }
            }
            else {
                it->second++;
            }
        }
        for (auto hit = hash.begin(); hit != hash.end(); hit++) {
            int cnt = 0, res = hit->first;
            for (int i = 0; i < nums.size(); i ++) {
                if (nums[i] == res)  cnt ++;
            }
            if (cnt > nums.size() / k) return res;
        }
    }
};
