#include <string>
#include <vector>
#include <map>

class Solution {
public:
    /**
     * @param strs: A list of strings
     * @return: A list of strings
     */
    vector<string> anagrams(vector<string> &strs) {
        // write your code here
        map<string, vector<string> > mp;
        for (int i = 0; i < strs.size(); i++) {
          string str = strs[i];
          sort(str.begin(), str.end());
          if (mp.find(str) == mp.end()) {
            vector<string> vec;
            vec.push_back(strs[i]);
            mp[str] = vec;
          } else {
            mp[str].push_back(strs[i]);
          }
        }
        vector<string> vec;
        for (auto res = mp.begin(); res != mp.end(); res ++) {
            if (res->second.size() >= 2) {
                for (int i = 0; i < res->second.size(); i ++) {
                    vec.push_back(res->second[i]);
                }
            }
        }
        return vec;
    }
};
