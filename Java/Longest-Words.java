class Solution {
    /**
     * @param dictionary: an array of strings
     * @return: an arraylist of strings
     */
    ArrayList<String> longestWords(String[] dictionary) {
        // write your code here
        int maxlen = -1;
        ArrayList<String> res = new ArrayList<String>();
        for (int i = 0; i < dictionary.length; i ++) {
            if (dictionary[i].length() > maxlen) {
                maxlen = dictionary[i].length();
                res.clear();
                res.add(dictionary[i]);
            } else if (dictionary[i].length() == maxlen) {
                res.add(dictionary[i]);
            }
        }
        return res;
    }
};
