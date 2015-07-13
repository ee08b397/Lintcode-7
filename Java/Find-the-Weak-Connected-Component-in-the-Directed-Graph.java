public class Solution {
    /**
     * @param nodes a array of Directed graph node
     * @return a connected set of a directed graph
     */
    public HashMap<Integer, Integer> bin;
    public int find(int x) {
        int y = x;
        while (bin.get(y) != y) {
            y = bin.get(y);
        }
        while (bin.get(x) != y) {
            int temp = bin.get(x);
            bin.put(x, y);
            x = temp;
        }
        return y;
    }
    public void merge(int x, int y) {
        int fx = find(x), fy = find(y);
        if (fx != fy) {
            bin.put(x, fy);
        }
    }
    public List<List<Integer>> connectedSet2(ArrayList<DirectedGraphNode> nodes) {
        // Write your code here
        bin = new HashMap<Integer, Integer>();
        for (int i = 0; i < nodes.size(); i ++) {
            bin.put(nodes.get(i).label, nodes.get(i).label);
        }
        List<List<Integer>> res = new ArrayList<List<Integer>>();
        for (int i = 0; i < nodes.size(); i ++) {
            int temp = nodes.get(i).label;
            for (int j = 0; j < nodes.get(i).neighbors.size(); j ++) {
                DirectedGraphNode cur = nodes.get(i).neighbors.get(j);
                merge(temp, cur.label);
            }
        }
        HashMap<Integer, List<Integer>> hash = new HashMap<Integer, List<Integer>>();
        for (int i = 0; i < nodes.size(); i ++) {
            int temp = nodes.get(i).label;
            int root = find(temp);
            if (hash.containsKey(root)) {
                hash.get(root).add(temp);
            } else {
                List<Integer> cnt = new ArrayList<Integer>();
                cnt.add(temp);
                hash.put(root, cnt);
            }
        }
        for (Integer key : hash.keySet()) {
            List<Integer> temp = new ArrayList<Integer>(hash.get(key));
            Collections.sort(temp);
            res.add(temp);
        }
        return res;
    }
}
