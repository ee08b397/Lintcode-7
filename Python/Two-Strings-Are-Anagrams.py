class Solution:
    """
    @param s: The first string
    @param b: The second string
    @return true or false
    """
    def anagram(self, s, t):
        # write your code here
        seq = [0] * 256
        for i in s:
            seq[ord(i)] += 1
        for i in t:
            seq[ord(i)] -= 1
            if seq[ord(i)] < 0:
                return False
        for i in range(256):
            if seq[i] != 0:
                return False
        return True
