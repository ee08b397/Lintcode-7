class Solution {
public:
    /*
     * @param k: The number k.
     * @return: The kth prime number as description.
     */
    long long kthPrimeNumber(int k) {
        // write your code here
        vector<long long> arr(k + 1);
        arr[0] = 1;
        int i3 = 0, i5 = 0, i7 = 0;
        for (int i = 1; i <= k; i ++) {
        	long long cur3 = arr[i3] * 3, cur5 = arr[i5] * 5, cur7 = arr[i7] * 7;
        	arr[i] = min(cur3, min(cur5, cur7));
        	if (arr[i] == cur3) i3 ++;
        	if (arr[i] == cur5) i5 ++;
        	if (arr[i] == cur7) i7 ++;
        }
        return arr[k];
    }
};
