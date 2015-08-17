class Solution:
    #param matrix: a matrix of 0 and 1
    #return: an integer
    def maxSquare(self, matrix):
        # write your code here
        res = 0
        lenx = len(matrix)
        leny = len(matrix[0])
        multilist = [[0 for col in range(leny)] for row in range(lenx)]
        for i in range(leny):
            if matrix[0][i] == 1:
                multilist[0][i] = 1
                res = 1
        for i in range(lenx):
            if matrix[i][0] == 1:
                multilist[i][0] = 1
                res = 1
        for i in xrange(1, lenx):
            for j in xrange(1, leny):
                if matrix[i][j] == 1:
                    multilist[i][j] = min(multilist[i - 1][j - 1], min(multilist[i][j - 1], multilist[i - 1][j])) + 1
                    res = max(res, multilist[i][j])
        return res * res