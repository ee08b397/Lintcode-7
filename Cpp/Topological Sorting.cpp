#include <algorithm>
#include <vector>
#include <set>

/**
 * Definition for Directed graph.
 */
struct DirectedGraphNode {
    int label;
    vector<DirectedGraphNode *> neighbors;
    DirectedGraphNode(int x) : label(x) {};
};

class Solution {
public:
    /**
     * @param graph: A list of Directed graph node
     * @return: Any topological order for the given graph.
     */
    void dfs(DirectedGraphNode *root, vector<DirectedGraphNode*> &vec, set<DirectedGraphNode*> &st) {
        for (int i = 0; i < root->neighbors.size(); i ++) {
            if (st.find((root->neighbors)[i]) == st.end()) {
                st.insert((root->neighbors)[i]);
                dfs((root->neighbors)[i], vec, st);
                vec.push_back((root->neighbors)[i]);
            }
        }
    }
    vector<DirectedGraphNode*> topSort(vector<DirectedGraphNode*> graph) {
        // write your code here
        vector<DirectedGraphNode*> vec, vec1;
        set<DirectedGraphNode*> hash;
        for (int i = 0; i < graph.size(); i ++) {
            if (hash.find(graph[i]) == hash.end()) {
                hash.insert(graph[i]);
                dfs(graph[i], vec, hash);
                vec.push_back(graph[i]);
            }
        }
        reverse(vec.begin(), vec.end());
        return vec;
    }
};
