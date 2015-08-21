# Definition for a Directed graph node
# class DirectedGraphNode:
#     def __init__(self, x):
#         self.label = x
#         self.neighbors = []

class Solution:
    """
    @param graph: A list of Directed graph node
    @param s: the starting Directed graph node
    @param t: the terminal Directed graph node
    @return: a boolean value
    """
    def hasRoute(self, graph, s, t):
        # write your code here
        q = []
        hash = {}
        hash[s] = 1
        q.append(s)
        while len(q) > 0:
            temp = q.pop(0)
            if temp is t:
                return True
            for item in temp.neighbors:
                if item not in hash:
                    hash[item] = 1
                    q.append(item)
        return False