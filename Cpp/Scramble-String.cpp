class Solution {
public:
    /**
     * @param s1 A string
     * @param s2 Another string
     * @return whether s2 is a scrambled string of s1
     */
    bool isScramble(string s1, string s2) {
        // Write your code here
        if (s1.size() != s2.size()) return false;
        vector<int> vis(26, 0);
        for (int i = 0; i < s1.size(); i ++) {
        	vis[s1[i] - 'a'] ++;
        }
        for (int i = 0; i < s2.size(); i ++) {
        	vis[s2[i] - 'a'] --;
        }
        for (int i = 0; i < 26; i ++) {
        	if (vis[i] != 0) return false;
        }
        if (s1 == s2 || (s1.size() == 1 && s2.size() == 1)) return true;
        for (int i = 1; i < s1.size(); i ++) {
        	bool res = isScramble(s1.substr(0, i), s2.substr(0, i)) && 
        		isScramble(s1.substr(i, s1.size() - i), s2.substr(i, s1.size() - i));
        	res = res || (isScramble(s1.substr(0, i), s2.substr(s2.size() - i, i)) && 
        		isScramble(s1.substr(i, s1.size() - i), s2.substr(0, s1.size() - i)));
        	if(res) return true;
        }
        return false;
    }
};
