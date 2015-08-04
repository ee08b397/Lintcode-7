class Solution:
    # @param s: a string
    # @return: a boolean
    def isUnique(self, str):
        # write your code here
        seq = [0] * 256
        for i in str:
            cur = ord(i)
            seq[cur] += 1
            if seq[cur] > 1:
                return False
        return True