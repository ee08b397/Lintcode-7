#include <string>
#include <set>

class Solution {
public:
    /**
     * @param str: a string
     * @return: a boolean
     */
    bool isUnique(string &str) {
        int vis[256];
        memset(vis, 0, sizeof(vis));
        for (int i = 0; i < str.size(); i++){
            if(vis[str[i]] == 0) vis[str[i]] = 1;
            else return false;
        }
        return true;
        // write your code here
    }
};
