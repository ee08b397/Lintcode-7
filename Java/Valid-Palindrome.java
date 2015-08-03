public class Solution {
    /**
     * @param s A string
     * @return Whether the string is a valid palindrome
     */
    public boolean isPalindrome(String s) {
        // Write your code here
        int left = 0, right = s.length() - 1;
        while (left < right) {
            while (left < right && !Character.isAlphabetic(s.charAt(left)) && !Character.isDigit(s.charAt(left))) left ++;
            while (left < right && !Character.isAlphabetic(s.charAt(right)) && !Character.isDigit(s.charAt(right))) right --;
            if (left < right) {
                char ch1, ch2;
                if (Character.isUpperCase(s.charAt(left))) ch1 = Character.toLowerCase(s.charAt(left));
                else ch1 = s.charAt(left);
                if (Character.isUpperCase(s.charAt(right))) ch2 = Character.toLowerCase(s.charAt(right));
                else ch2 = s.charAt(right);
                if (ch1 != ch2) return false;
                left ++;
                right --;
            }
        }
        return true;
    }
}