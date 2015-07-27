#include <vector>
#include <map>

/**
 * Definition for undirected graph.
 */
struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
};


class Solution {
public:
    /**
     * @param node: A undirected graph node
     * @return: A undirected graph node
     */
    UndirectedGraphNode* dfs(UndirectedGraphNode* root, map<UndirectedGraphNode*, UndirectedGraphNode*> &hash) {
        if (hash.find(root) != hash.end()) return hash[root];
        UndirectedGraphNode *node = new UndirectedGraphNode(root->label);
        hash[root] = node;
        for (auto nbr : root->neighbors) {
            node->neighbors.push_back(dfs(nbr, hash));
        }
        return node;
    }
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        // write your code here
        if (node == nullptr) return nullptr;
        map<UndirectedGraphNode*, UndirectedGraphNode*> hash;
        dfs(node, hash);
        return hash[node];
    }
};
