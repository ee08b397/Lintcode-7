class Solution:
    # @param {string} s A string
    # @return {boolean} whether the string is a valid parentheses
    def isValidParentheses(self, s):
        # Write your code here
        q = []
        for i in s:
            if i == '(' or i == '[' or i == '{':
                q.append(i);
            elif i == ')':
                if len(q) == 0 or q.pop() != '(':
                    return False
            elif i == ']':
                if len(q) == 0 or q.pop() != '[':
                    return False
            elif i == '}':
                if len(q) == 0 or q.pop() != '{':
                    return False
        if len(q) == 0:
            return True
        else:
            return False