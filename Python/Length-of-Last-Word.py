class Solution:
    # @param {string} s A string
    # @return {int} the length of last word
    def lengthOfLastWord(self, s):
        # Write your code here
        p = len(s) - 1
        while p >= 0 and s[p] == ' ':
            p -= 1
        if p < 0:
            return 0
        cur = 0
        while p >= 0 and s[p] != ' ':
            cur += 1
            p -= 1
        return cur