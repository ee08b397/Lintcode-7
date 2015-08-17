class MinStack(object):
    def __init__(self):
        # do some intialize if necessary
        self.stk1 = []
        self.stk2 = []
    def push(self, number):
        # write yout code here
        self.stk1.append(number)
        if len(self.stk2) == 0 or number <= self.stk2[-1]:
            self.stk2.append(number)
    def pop(self):
        # pop and return the top item in stack
        cur = self.stk1.pop()
        if cur <=  self.stk2[-1]:
            self.stk2.pop()
        return cur
    def min(self):
        # return the minimum number in stack
        return self.stk2[-1]