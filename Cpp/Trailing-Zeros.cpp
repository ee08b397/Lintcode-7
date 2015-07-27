class Solution {
public:
    // param n : description of n
    // return: description of return
    long long trailingZeros(long long n) {
        long long res = 5, cnt = 0;
        while (res <= n) {
            cnt += n / res;
            res *= 5;
        }
        return cnt;
    }
};
