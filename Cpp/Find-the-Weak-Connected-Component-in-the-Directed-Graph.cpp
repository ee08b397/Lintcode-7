/**
 * Definition for Directed graph.
 * struct DirectedGraphNode {
 *     int label;
 *     vector<DirectedGraphNode *> neighbors;
 *     DirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
private:
	unordered_map<int, int> bin;
public:
    /**
     * @param nodes a array of directed graph node
     * @return a connected set of a directed graph
     */
    int find(int x) {
    	int temp = x, y = x;
    	while (bin[temp] != temp) {
    		temp = bin[temp];
    	}
    	while (y != temp) {
    		int cnt = bin[y];
    		bin[y] = temp;
    		y = cnt;
    	}
    	return temp;
    }
    void merge(int x, int y) {
    	int fx = find(x), fy = find(y);
    	if (fx != fy) {
    		bin[fx] = fy;
    	}
    }
    vector<vector<int> > connectedSet2(vector<DirectedGraphNode*>& nodes) {
        // Write your code here
        for (int i = 0; i < nodes.size(); i ++) {
        	bin[nodes[i]->label] = nodes[i]->label;
        }
    	vector<vector<int> > res;
    	for (int i = 0; i < nodes.size(); i ++) {
    		int temp =  nodes[i]->label;
    		for (int j = 0; j < nodes[i]->neighbors.size(); j++) {
    			DirectedGraphNode *cur = nodes[i]->neighbors[j];
    			merge(temp, cur->label);
    		}
    	}
    	map<int, vector<int> > h;
    	for (int i = 0; i < nodes.size(); i ++) {
    		int temp = nodes[i]->label;
    		int root = find(temp);
    		if (h.find(root) == h.end()) {
    			vector<int> cnt(1, temp);
    			h.insert(make_pair(root, cnt));
    		} else {
    			h[root].push_back(temp);
    		}
    	}
    	auto cur = h.begin();
    	while (cur != h.end()) {
    		vector<int> temp;
    		temp = (*cur).second;
    		sort(temp.begin(), temp.end());
    		res.push_back(temp);
    		cur ++;
    	}
    	return res;
    }
};
