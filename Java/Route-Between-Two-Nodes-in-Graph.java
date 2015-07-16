/**
 * Definition for Directed graph.
 * class DirectedGraphNode {
 *     int label;
 *     ArrayList<DirectedGraphNode> neighbors;
 *     DirectedGraphNode(int x) {
 *         label = x;
 *         neighbors = new ArrayList<DirectedGraphNode>();
 *     }
 * };
 */
public class Solution {
   /**
     * @param graph: A list of Directed graph node
     * @param s: the starting Directed graph node
     * @param t: the terminal Directed graph node
     * @return: a boolean value
     */
   public boolean hasRoute(ArrayList<DirectedGraphNode> graph,
                            DirectedGraphNode s, DirectedGraphNode t) {
        // write your code here
        Queue<DirectedGraphNode> q = new LinkedList<DirectedGraphNode>();
        HashSet<DirectedGraphNode> hash = new HashSet<DirectedGraphNode>();
        q.offer(s);
        hash.add(s);
        while (!q.isEmpty()) {
            DirectedGraphNode cur = q.poll();
            if (cur == t) return true;
            for (int i = 0; i < cur.neighbors.size(); i ++) {
                DirectedGraphNode temp = cur.neighbors.get(i);
                //if (temp == t) return true;
                if (!hash.contains(temp)) {
                    hash.add(temp);
                    q.offer(temp);
                }
            }
        }
        return false;
    }
}
