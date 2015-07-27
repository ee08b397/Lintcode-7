class Solution {
public:
    /**
     * @param A: A string includes Upper Case letters
     * @param B: A string includes Upper Case letter
     * @return:  if string A contains all of the characters in B return true
     *           else return false
     */
    bool compareStrings(string A, string B) {
        int vis1[26], vis2[26];
        memset(vis1, 0, sizeof(vis1));
        memset(vis2, 0, siezof(vis2));
        for (int i = 0; i < A.size(); i ++) {
          vis1[A[i]-'A'] ++;
        }
        for (int i = 0; i < B.size(); i ++) {
          vis2[B[i]-'A'] ++;
        }
        for (int i = 0; i < 26; i ++) {
          if(vis1[i] < vis2[i]) return false;
        }
        return true;
        // write your code here
    }
};
