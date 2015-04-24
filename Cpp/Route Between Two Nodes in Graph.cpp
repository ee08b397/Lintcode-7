#include <queue>
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
     * @param s: the starting Directed graph node
     * @param t: the terminal Directed graph node
     * @return: a boolean value
     */
    bool dfs(DirectedGraphNode *s, DirectedGraphNode *t, set<DirectedGraphNode*> &st) {
        if (s == t) return true;
        st.insert(s);
        for(int i = 0; i < s->neighbors.size(); i ++) {
            if (st.find((s->neighbors)[i]) == st.end()) {
                if (dfs((s->neighbors)[i], t, st)) return true;
            }
        }
        return false;
    }
    bool hasRoute(vector<DirectedGraphNode*> graph,
        DirectedGraphNode* s, DirectedGraphNode* t) {
        // write your code here
        set<DirectedGraphNode*> st;
        return dfs(s, t, st);
    }
};


