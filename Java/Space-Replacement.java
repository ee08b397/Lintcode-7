public class Solution {
    /**
     * @param string: An array of Char
     * @param length: The true length of the string
     * @return: The true length of new string
     */
    public int replaceBlank(char[] string, int length) {
        // Write your code here
        int num = 0;
        for (int i = 0; i < length; i ++) {
            if (string[i] == ' ') num ++;
        }
        int cur = num * 2 + length - 1;
        int pos = length - 1;
        while (cur >= 0) {
            if (string[pos] != ' ') {
                string[cur--] = string[pos--];
            } else {
                pos --;
                string[cur--] = '0';
                string[cur--] = '2';
                string[cur--] = '%';
            }
        }
        return num * 2 + length;
    }
}
