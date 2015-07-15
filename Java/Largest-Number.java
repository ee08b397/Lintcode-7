public class Solution {
    /**
     *@param num: A list of non negative integers
     *@return: A string
     */
    private class StringComparator implements Comparator<String> {
        public int compare(String s1, String s2) {
            return (s2 + s1).compareTo(s1 + s2);
        }
    }
    public String largestNumber(int[] num) {
        // write your code here
        ArrayList<String> res = new ArrayList<String>();
        for (int i = 0; i < num.length; i ++) {
            res.add(String.valueOf(num[i]));
        }
        Collections.sort(res, new StringComparator());
        StringBuffer str = new StringBuffer();
        for (int i = 0; i < res.size(); i ++) {
            str.append(res.get(i));
        }
        String result = str.toString();
        int index = 0;
        while (index < result.length() && result.charAt(index) == '0') {
            index++;
        }
        if (index == result.length()) {
            return "0";
        }
        return result.substring(index);
    }
}