class Solution:
    # @param s : A string
    # @return : A string
    def reverseWords(self, s):
        # write your code here
        if s is None or len(s) == 0:
            return s
        seq = s.split()
        if len(seq) == 0:
            return ""
        seq.reverse()
        seq = " ".join(seq)
        return seq