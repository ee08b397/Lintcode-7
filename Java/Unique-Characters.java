public class Solution {
    /**
     * @param str: a string
     * @return: a boolean
     */
    public boolean isUnique(String str) {
        // write your code here
        int[] vis = new int[256];
        for (int i = 0; i < str.length(); i ++) {
            if(vis[str.charAt(i)] ++ > 0) return false;
        }
        return true;
    }
}