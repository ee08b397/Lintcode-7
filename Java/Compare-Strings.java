public class Solution {
    /**
     * @param A : A string includes Upper Case letters
     * @param B : A string includes Upper Case letter
     * @return :  if string A contains all of the characters in B return true else return false
     * Time complexity: O(N)
     */
    public boolean compareStrings(String A, String B) {
        // write your code here
        int []vis = new int[26];
        for (int i = 0; i < A.length(); i ++) {
        	int temp = (int)(A.charAt(i) - 'A');
        	vis[temp] ++;
        }
        for (int i = 0; i < B.length(); i ++) {
        	int temp = (int)(B.charAt(i) - 'A');
        	if (vis[temp] == 0) return false;
        	vis[temp] --;
        }
        return true;
    }
}
