class Solution:
    # @param s: a string
    # @return: an integer
    def lengthOfLongestSubstring(self, s):
        # write your code here
        maxl = 0
        start = 0
        seq = [0] * 256
        for i in xrange(len(s)):
            cur = ord(s[i])
            seq[cur] += 1
            while seq[cur] >= 2:
                seq[ord(s[start])] -= 1
                start += 1
            maxl = max(maxl, i - start + 1)
        return maxl