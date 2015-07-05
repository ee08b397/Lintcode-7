public class Solution {
    
    /**
     * @param graph: A list of Directed graph node
     * @return: Any topological order for the given graph.
     */
    public ArrayList<DirectedGraphNode> topSort(ArrayList<DirectedGraphNode> graph) {
        // write your code here
        ArrayList<DirectedGraphNode>  res = new ArrayList<DirectedGraphNode>();
        HashMap<DirectedGraphNode, Integer> map = new HashMap<DirectedGraphNode, Integer>();
        for (DirectedGraphNode node : graph) {
            for (DirectedGraphNode cnt : node.neighbors) {
                if (map.containsKey(cnt)) {
                    map.put(cnt, map.get(cnt) + 1);
                } else {
                    map.put(cnt, 1);
                }
            }
        }
        Queue<DirectedGraphNode> q = new LinkedList<DirectedGraphNode>();
        for (DirectedGraphNode node : graph) {
            if (!map.containsKey(node)) {
                q.offer(node);
                res.add(node);
            }
        }
        while (!q.isEmpty()) {
            DirectedGraphNode temp = q.poll();
            for (DirectedGraphNode cnt : temp.neighbors) {
                map.put(cnt, map.get(cnt) - 1);
                if (map.get(cnt) == 0) {
                    res.add(cnt);
                    q.offer(cnt);
                }
            }
        }
        return res;
    }
}

