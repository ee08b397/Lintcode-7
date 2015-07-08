public class Solution {
    /**
     * @param start, a string
     * @param end, a string
     * @param dict, a set of string
     * @return an integer
     */
    private String replace(String s, int index, char c) {
        char[] chars = s.toCharArray();
        chars[index] = c;
        return new String(chars);
    }
    public int ladderLength(String start, String end, Set<String> dict) {
        // write your code here
        if (dict == null || dict.size() == 0) return 0;
        Queue<String> q = new LinkedList<String>();
        q.offer(start);
        dict.remove(start);
        int length = 1;
        while (!q.isEmpty()) {
            int count = q.size();
            for (int i = 0; i < count; i ++) {
                String current = q.poll();
                for (char c = 'a'; c <= 'z'; c ++) {
                    for (int j = 0; j < current.length(); j ++) {
                        if (c == current.charAt(j)) continue;
                        String temp = replace(current, j, c);
                        if (temp.equals(end)) return length + 1;
                        if (dict.contains(temp)) {
                            dict.remove(temp);
                            q.offer(temp);
                        }
                    }
                }
            }
            length ++;
        }
        return 0;
    }
}