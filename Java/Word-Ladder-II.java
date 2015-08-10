public class Solution {
    public List<List<String>> findLadders(String start, String end,
                                          Set<String> dict) {
        List<List<String>> ladders = new ArrayList<List<String>>();
        Map<String, List<String>> map = new HashMap<String, List<String>>();
        Map<String, Integer> distance = new HashMap<String, Integer>();

        dict.add(start);
        dict.add(end);

        bfs(map, distance, start, end, dict);

        List<String> path = new ArrayList<String>();

        dfs(ladders, path, end, start, distance, map);

        return ladders;
    }

    void dfs(List<List<String>> ladders, List<String> path, String crt,
             String start, Map<String, Integer> distance,
             Map<String, List<String>> map) {
        path.add(crt);
        if (crt.equals(start)) {
            Collections.reverse(path);
            ladders.add(new ArrayList<String>(path));
            Collections.reverse(path);
        } else {
            for (String next : map.get(crt)) {
                if (distance.containsKey(next) && distance.get(crt) == distance.get(next) + 1) {
                    dfs(ladders, path, next, start, distance, map);
                }
            }
        }
        path.remove(path.size() - 1);
    }

    void bfs(Map<String, List<String>> map, Map<String, Integer> distance,
             String start, String end, Set<String> dict) {
        Queue<String> q = new LinkedList<String>();
        q.offer(start);
        distance.put(start, 0);
        for (String s : dict) {
            map.put(s, new ArrayList<String>());
        }

        while (!q.isEmpty()) {
            String crt = q.poll();

            List<String> nextList = expand(crt, dict);
            for (String next : nextList) {
                map.get(next).add(crt);
                if (!distance.containsKey(next)) {
                    distance.put(next, distance.get(crt) + 1);
                    q.offer(next);
                }
            }
        }
    }

    List<String> expand(String crt, Set<String> dict) {
        List<String> expansion = new ArrayList<String>();

        for (int i = 0; i < crt.length(); i++) {
            for (char ch = 'a'; ch <= 'z'; ch++) {
                if (ch != crt.charAt(i)) {
                    String expanded = crt.substring(0, i) + ch
                            + crt.substring(i + 1);
                    if (dict.contains(expanded)) {
                        expansion.add(expanded);
                    }
                }
            }
        }

        return expansion;
    }
}


//Solution2
class Node {
    public int dist;
    public String str;
    public LinkedList<Node> prev;
    public Node(int dist, String str) {
        this.dist = dist;
        this.str = str;
        this.prev = new LinkedList<Node>();
    }
    public void addprev(Node pNode) {
        prev.add(pNode);
    }
}
public class Solution {
    /**
     * @param start, a string
     * @param end, a string
     * @param dict, a set of string
     * @return a list of lists of string
     */
    public String replace(String str, int pos, char ch) {
        StringBuffer sb = new StringBuffer(str);
        sb.setCharAt(pos, ch);
        return sb.toString();
    }
    // Get all the paths by using DFS.
    private void getPaths(Node end, HashMap<String, Node> map,
                          List<String> curPath, List<List<String>> paths) {
        if (end == null) {
            paths.add(curPath);
            return;
        }

        curPath.add(0, end.str);
        if (!end.prev.isEmpty()) {
            for (Node prevNode : end.prev) {
                getPaths(prevNode, map, new ArrayList<String>(curPath), paths);
            }
        } else {
            getPaths(null, map, curPath, paths);
        }
    }
    public List<List<String>> findLadders(String start, String end, Set<String> dict) {
        // write your code here
        dict.add(end);
        HashMap<String, Node> map = new HashMap<String, Node>();
        Queue<String> q = new LinkedList<String>();
        Node startNode = new Node(1, start);
        q.offer(start);
        map.put(start, startNode);
        List<List<String>> res = new ArrayList<List<String>>();
        while (!q.isEmpty()) {
            String str = q.poll();
            if (str.equals(end)) {
                getPaths(map.get(end), map, new ArrayList<String>(), res);
                return res;
            }
            for (int i = 0; i < str.length(); i ++) {
                for (int j = 0; j < 26; j ++) {
                    char c = (char)('a' + j);
                    String New_Str = replace(str, i, c);
                    if (dict.contains(New_Str)) {
                        if (!map.containsKey(New_Str)) {
                            Node node = map.get(str);
                            Node Newnode = new Node(node.dist + 1, New_Str);
                            Newnode.prev.add(node);
                            map.put(New_Str, Newnode);
                            q.offer(New_Str);
                        } else {
                            Node node = map.get(New_Str);
                            Node prevnode = map.get(str);
                            if (node.dist == prevnode.dist + 1) {
                                node.prev.add(prevnode);
                            }
                        }
                    }
                }
            }
        }
        return res;
    }
}