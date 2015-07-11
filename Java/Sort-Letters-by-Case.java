public class Solution {
    /**
     *@param chars: The letter array you should sort by Case
     *@return: void
     */
    public boolean isupper(char ch) {
        if (ch >= 'a' && ch <= 'z') return false;
        else return true;
    }
    public void sortLetters(char[] chars) {
        //write your code here
        int left = 0, right = chars.length - 1;
        while (left < right) {
            while (left < right && !isupper(chars[left])) {
                left ++;
            }
            while (left < right && isupper(chars[right])) {
                right --;
            }
            if (left < right) {
                char temp = chars[left];
                chars[left] = chars[right];
                chars[right] = temp;
            }
        }
    }
}

