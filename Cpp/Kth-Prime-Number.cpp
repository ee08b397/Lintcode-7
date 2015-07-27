class Solution {
public:
    long long kthPrimeNumber(int k) {

        vector<long long>  h(k+1, 0);

        h[0] = 1;
        int i3 = 0, i5 = 0, i7 = 0;

        for(int i = 1; i <= k; i++) {
            long long x3 = 3 * h[i3], x5 = 5*h[i5], x7 = 7 * h[i7];
            h[i] = min(x3, min(x5, x7));

            if (x3 == h[i]) i3++;
            if (x5 == h[i]) i5++;
            if (x7 == h[i]) i7++;
        }

        return h[k];
    }
};
