#include <vector>
#include <stack>

class Solution {
public:
    /**
     * @param n a number
     * @return Gray code
     */
    vector<int> grayCode(int n) {
        // Write your code here
        vector<int> res;
        int m = 1 << n;
        for (int i = 0; i < m; i ++) {
            res.push_back(i ^ (i >> 1));
        }
        return res;
    }
};
