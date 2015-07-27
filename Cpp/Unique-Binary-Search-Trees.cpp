class Solution {
public:
    /**
     * @paramn n: An integer
     * @return: An integer
     */
    int numTrees(int n) {
        // write your code here
        if (n <= 1) return 1;
        int *arr = new int[n+1];
        arr[0] = arr[1] = 1;
        for (int i = 2; i <= n ; i++) {
            arr[i] = 0;
            for (int j = 0; j < i; j ++) {
                arr[i] += (arr[j] * arr[i-j-1]);
            }
        }
        int res = arr[n];
        delete [] arr;
        return res;
    }
};
