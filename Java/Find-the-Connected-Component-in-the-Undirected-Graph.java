class UndirectedGraphNode {
    int label;
    ArrayList<UndirectedGraphNode> neighbors;
    UndirectedGraphNode(int x) { label = x; neighbors = new ArrayList<UndirectedGraphNode>(); }
};

public class Solution {
    /**
     * @param nodes a array of Undirected graph node
     * @return a connected set of a Undirected graph
     */
    public void dfs(UndirectedGraphNode cur, List<Integer> temp, Set<UndirectedGraphNode> hash) {
        if (cur == null) return;
        temp.add(cur.label);
        hash.add(cur);
        for (int i = 0; i < cur.neighbors.size(); i ++) {
            UndirectedGraphNode cnt = cur.neighbors.get(i);
            if (!hash.contains(cnt)) dfs(cnt, temp, hash);
        }
    }
    public List<List<Integer>> connectedSet(ArrayList<UndirectedGraphNode> nodes) {
        // Write your code here
        List<List<Integer> > list = new LinkedList<List<Integer>>();
        Set<UndirectedGraphNode> hash = new HashSet<UndirectedGraphNode>();
        for (int i = 0; i < nodes.size(); i ++) {
            UndirectedGraphNode cur = nodes.get(i);
            if (!hash.contains(cur)) {
                List<Integer> temp = new ArrayList<Integer>();
                dfs(cur, temp, hash);
                Collections.sort(temp);
                list.add(temp);
            }
        }
        return list;
    }
}