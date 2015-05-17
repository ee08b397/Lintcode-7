#include <cstring>
#include <vector>

class Solution {
public:
    /**
     * @param s: A string
     * @param p: A string includes "." and "*"
     * @return: A boolean
     */
    bool isMatch(const char *s, const char *p) {
        // write your code here
        int lens = strlen(s), lenp = strlen(p);
        vector<vector<int> > vis(lens + 1, vector<int> (lenp + 1));
        vis[0][0] = 1;
        for (int i = 1; i <= lenp; i ++) {
            if (p[i-1] == '*' && i >= 2) vis[0][i] = vis[0][i-2];
        }
        for (int i = 0; i < lens; i ++) {
            for (int j = 0; j < lenp; j ++) {
                if (p[j] != '*' && (p[j] == '.' || s[i] == p[j])) {
                    vis[i+1][j+1] = vis[i][j];
                } else if(p[j] == '*') {
                    if (vis[i+1][j-1] || vis[i+1][j]) vis[i+1][j+1] = 1;
                    else if (vis[i][j+1] && (s[i] == p[j-1] || p[j-1] == '.')) vis[i+1][j+1] = 1;
                }
            }
        }
        return vis[lens][lenp];
    }
};
