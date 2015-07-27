#include <vector>

class Solution {
public:
    /**
     *@param L: Given n pieces of wood with length L[i]
     *@param k: An integer
     *return: The maximum length of the small pieces.
     */
    bool CanCut(vector<int> &L, int k, int len) {
        int num = 0;
        for (int i = 0; i < L.size(); i ++) {
            num += L[i] / len;
        }
        if (num >= k) return true;
        else return false;
    }
    int woodCut(vector<int> L, int k) {
        // write your code here
        if (L.empty()) return 0;
        int maxlen = L[0], minlen = 1, mid, res = 0;
        for (int i = 1; i < L.size(); i ++) {
            maxlen = max(maxlen, L[i]);
        }
        while (minlen <= maxlen) {
            mid = minlen + (maxlen - minlen) / 2;
            if (CanCut(L, k, mid)) {
                res = max(res, mid);
                minlen = mid + 1;
            } else {
                maxlen = mid - 1;
            }
        }
        return res;
    }
};
