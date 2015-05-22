#include <vector>

class Solution{
public:
    /**
     * @param n: an integer
     * @return an integer f(n)
     */
    int fibonacci(int n) {
        // write your code here
        vector<int> fib(n);
        fib[0] = 0, fib[1] = 1;
        for (int i = 2; i < n; i ++) {
            fib[i] = fib[i - 1] + fib[i - 2];
        }
        return fib[n-1];
    }
};

