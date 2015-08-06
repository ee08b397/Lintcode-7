class Solution:
    """
    @param A : A string includes Upper Case letters
    @param B : A string includes Upper Case letters
    @return :  if string A contains all of the characters in B return True else return False
    """
    def compareStrings(self, A, B):
        # write your code here
        if B is None or len(B) == 0:
            return True
        vis = [0] * 256
        for i in A:
            vis[ord(i)] += 1
        for i in B:
            vis[ord(i)] -= 1
            if vis[ord(i)] < 0:
                return False
        return True