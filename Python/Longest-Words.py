class Solution:
    # @param dictionary: a list of strings
    # @return: a list of strings
    def longestWords(self, dictionary):
        # write your code here
        cur = 0
        res = []
        for i in dictionary:
            if len(i) == cur:
                res.append(i)
            elif len(i) > cur:
                cur = len(i)
                res = []
                res.append(i)
        return res