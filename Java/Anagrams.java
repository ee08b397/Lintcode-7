public class Solution {
    /**
     * @param strs: A list of strings
     * @return: A list of strings
     */
    public List<String> anagrams(String[] strs) {
        // write your code here
        HashMap<String, List<String>> hash = new HashMap<String, List<String>>();
        for (int i = 0; i < strs.length; i ++) {
            ArrayList<Character> res = new ArrayList<Character>();
            for (int j = 0; j < strs[i].length(); j ++) {
                res.add(strs[i].charAt(j));
            }
            Collections.sort(res);
            StringBuffer sb = new StringBuffer();
            for (int k = 0; k < res.size(); k ++) {
                sb.append(res.get(k));
            }
            String s = sb.toString();
            if (hash.containsKey(s)) {
                hash.get(s).add(strs[i]);
            } else {
                List<String> cur = new LinkedList<String>();
                cur.add(strs[i]);
                hash.put(s, cur);
            }
        }
        List<String> res = new LinkedList<String>();
        for (String key : hash.keySet()) {
            if (hash.get(key).size() >= 2) {
                res.addAll(hash.get(key));
            }
        }
        return res;
    }
}