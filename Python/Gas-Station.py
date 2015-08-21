class Solution:
    # @param gas, a list of integers
    # @param cost, a list of integers
    # @return an integer
    def canCompleteCircuit(self, gas, cost):
        # write your code here
        res = 0
        cur = 0
        index = 0
        for i in range(len(gas)):
            if cur < 0:
                cur = 0
                index = i
            res += (gas[i] - cost[i])
            cur += (gas[i] - cost[i])
        if res < 0:
            return -1
        return index