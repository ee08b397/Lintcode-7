/**
 * Definition for Undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    /**
     * @param nodes a array of Undirected graph node
     * @return a connected set of a Undirected graph
     */
    void dfs(unordered_set<UndirectedGraphNode*> &hash, vector<int> &cur, UndirectedGraphNode* cnt) {
    	hash.insert(cnt);
    	cur.push_back(cnt->label);
    	for (int i = 0; i < cnt->neighbors.size(); i ++) {
    		UndirectedGraphNode *temp = cnt->neighbors[i];
    		if (hash.find(temp) == hash.end()) dfs(hash, cur, temp);
    	}
    }
    vector<vector<int> > connectedSet(vector<UndirectedGraphNode*>& nodes) {
        // Write your code here
        vector<vector<int> > res;
        unordered_set<UndirectedGraphNode*> hash;
        for (int i = 0; i < nodes.size(); i ++) {
        	if (hash.find(nodes[i]) == hash.end()) {
        		vector<int> cur;
        		dfs(hash, cur, nodes[i]);
        		sort(cur.begin(), cur.end());
        		res.push_back(cur);
        	}
        }
        return res;
    }
};
