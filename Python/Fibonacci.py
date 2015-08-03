class Solution:
    # @param n: an integer
    # @return an integer f(n)
    def fibonacci(self, n):
        # write your code here
        fib = []
        fib.append(0)
        fib.append(1)
        for i in range(2, n):
            fib.append(fib[i - 1] + fib[i - 2])
        return fib[n - 1]
