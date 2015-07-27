#include <vector>

class Solution {
public:
    /**
     * @param n: An integer.
     * return : An array storing 1 to the largest number with n digits.
     */
    void recur(int pos, int n, vector<int> &res) {
        if (pos > n) return;
        int left = 1;
        for (int i = 1; i < pos; i ++) {
            left *= 10;
        }
        for (int i = left; i < left * 10; i ++) {
            res.push_back(i);
        }
        recur(pos + 1, n, res);
    }
    vector<int> numbersByRecursion(int n) {
        // write your code here
        vector<int> res;
        recur(1, n, res);
        return res;
    }
};
