class Solution:
    # @param {char[]} string: An array of Char
    # @param {int} length: The true length of the string
    # @return {int} The true length of new string
    def replaceBlank(self, string, length):
        # Write your code here
        num = 0
        for i in range(length):
            if string[i] == ' ':
                num += 1
        cur = num * 2 + length - 1
        cnt = length - 1
        while cur >= 0:
            if string[cnt] == ' ':
                string[cur] = '0'
                cur -= 1
                string[cur] = '2'
                cur -= 1
                string[cur] = '%'
                cur -= 1
            else:
                string[cur] = string[cnt]
                cur -= 1
            cnt -= 1
        return num * 2 + length
