class Solution {
public:
    /**
     * @param string: An array of Char
     * @param length: The true length of the string
     * @return: The true length of new string
     */
    int replaceBlank(char string[], int length) {
        // Write your code here
        int num = 0;
        if (length == 0) return 0;
        for (int i = 0; i < length; i ++) {
            if (string[i] == ' ') num ++;
        }
        int pos1 = length + 2 * num, pos2 = length;
        while (pos2 >= 0) {
            if (string[pos2] == ' ') {
                string[pos1--] = '0';
                string[pos1--] = '2';
                string[pos1--] = '%';
                pos2 --;
            } else {
                string[pos1--] = string[pos2--];
            }
        }
        return length + 2 * num;
    }
};
