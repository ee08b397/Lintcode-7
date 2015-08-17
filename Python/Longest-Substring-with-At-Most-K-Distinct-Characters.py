class Solution:
    # @param s : A string
    # @return : An integer
    def lengthOfLongestSubstringKDistinct(self, s, k):
        # write your code here
        maxl = 0
        start = 0
        seq = [0] * 256
        num = 0
        for i in xrange(len(s)):
            cur = ord(s[i])
            if seq[cur] == 0:
                num += 1
            seq[cur] += 1
            while num > k:
                seq[ord(s[start])] -= 1
                if seq[ord(s[start])] == 0:
                    num -= 1
                start += 1
            maxl = max(maxl, i - start + 1)
        return maxl