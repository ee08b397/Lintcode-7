# Definition for a undirected graph node
# class UndirectedGraphNode:
#     def __init__(self, x):
#         self.label = x
#         self.neighbors = []
class Solution:
    # @param {UndirectedGraphNode[]} nodes a array of undirected graph node
    # @return {int[][]} a connected set of a undirected graph
    def helper(self, node, seq, dict):
        dict[node] = 1
        seq.append(node.label)
        for item in node.neighbors:
            if item not in dict:
                self.helper(item, seq, dict)

    def connectedSet(self, nodes):
        # Write your code here
        res = []
        dict = {}
        for item in nodes:
            if item not in dict:
                seq = []
                self.helper(item, seq, dict)
                seq.sort()
                res.append(seq)
        return res