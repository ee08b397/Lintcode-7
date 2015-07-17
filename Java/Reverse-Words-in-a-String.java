public class Solution {
    /**
     * @param s : A string
     * @return : A string
     */
    public String reverseWords(String s) {
        // write your code
        String stringarray[] = s.split(" ");
        StringBuffer sb = new StringBuffer();
        int sign = 0;
        for (int i = stringarray.length - 1; i >= 0; i --) {
            if (stringarray[i] != " ") {
                if (sign == 0) {
                    sb.append(stringarray[i]);
                    sign = 1;
                }else {
                    sb.append(" ");
                    sb.append(stringarray[i]);
                }
            }
        }
        return sb.toString();
    }
}