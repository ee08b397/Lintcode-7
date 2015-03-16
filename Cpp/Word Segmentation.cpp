class Solution {
public:
    /**
     * @param s: A string s
     * @param dict: A dictionary of words dict
     */
    bool wordSegmentation(string s, unordered_set<string> &dict) {
        int n = s.length();
        if (n < 1) return true;

        char chrs[256] = {0};

        for(string word : dict) {
            for(char c : word) {
                chrs[c]++;
            }
        }

        for(char c : s) {
            if (chrs[c] == 0)
              return false;
        }

        vector<bool> canBreak(n, false);

        for(int i = 0; i < n; i++) {
            for(int j = i; j >=0; j--) {
                if( (j== 0 || canBreak[j-1]) &&dict.count(s.substr(j, i-j+1))) {
                    canBreak[i] = true;
                    break;
                }
            }
        }

        return canBreak[n-1];
    }
};
