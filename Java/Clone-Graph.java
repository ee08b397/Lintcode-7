/**
 * Definition for undirected graph.
 * class UndirectedGraphNode {
 *     int label;
 *     ArrayList<UndirectedGraphNode> neighbors;
 *     UndirectedGraphNode(int x) { label = x; neighbors = new ArrayList<UndirectedGraphNode>(); }
 * };
 */
public class Solution {
    /**
     * @param node: A undirected graph node
     * @return: A undirected graph node
     */
    public void helper(HashMap<Integer, UndirectedGraphNode> hash, UndirectedGraphNode root, UndirectedGraphNode node) {
        for (int i = 0; i < node.neighbors.size(); i ++) {
            UndirectedGraphNode temp = node.neighbors.get(i);
            if (hash.containsKey(temp.label)) {
                root.neighbors.add(hash.get(temp.label));
                //helper(hash, hash.get(temp.label), temp);
            } else {
                UndirectedGraphNode cur = new UndirectedGraphNode(temp.label);
                hash.put(temp.label, cur);
                root.neighbors.add(cur);
                helper(hash, cur, temp);
            }
        }
    }
    public UndirectedGraphNode cloneGraph(UndirectedGraphNode node) {
        // write your code here
        if (node == null) return null;
        HashMap<Integer, UndirectedGraphNode> hash = new HashMap<Integer, UndirectedGraphNode>();
        UndirectedGraphNode root = new UndirectedGraphNode(node.label);
        hash.put(root.label, root);
        helper(hash, root, node);
        return root;
    }
}

public class Solution {
    /**
     * @param node: A undirected graph node
     * @return: A undirected graph node
     */
    public UndirectedGraphNode helper(UndirectedGraphNode node, HashMap<UndirectedGraphNode, UndirectedGraphNode> hash) {
        if (hash.containsKey(node)) return hash.get(node);
        UndirectedGraphNode cur = new UndirectedGraphNode(node.label);
        hash.put(node, cur);
        for (int i = 0; i < node.neighbors.size(); i ++) {
            cur.neighbors.add(helper(node.neighbors.get(i), hash));
        }
        return cur;
    }
    public UndirectedGraphNode cloneGraph(UndirectedGraphNode node) {
        // write your code here
        if (node == null) return null;
        HashMap<UndirectedGraphNode, UndirectedGraphNode> hash = new HashMap<UndirectedGraphNode, UndirectedGraphNode>();
        helper(node, hash);
        return hash.get(node);
    }
}