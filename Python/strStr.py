class Solution:
    def strStr(self, source, target):
        # write your code here
        if source is None or target is None:
            return -1
        if source == target:
            return 0
        lens = len(source)
        lent = len(target)
        for i in range(lens):
            if i + lent - 1 >= lens:
                break
            flag = True
            for j in range(lent):
                if source[j + i] != target[j]:
                    flag = False
                    break
            if flag:
                return i
        return -1
