class Solution:
    # @param strs: A list of strings
    # @return: A list of strings
    def anagrams(self, strs):
        # write your code here
        res = []
        dict = {}
        for item in strs:
            temp = "".join(sorted(item))
            if temp not in dict:
                dict[temp] = []
            dict[temp].append(item[:])
        for item in dict:
            if len(dict[item]) >= 2:
                res += dict[item]
        return res