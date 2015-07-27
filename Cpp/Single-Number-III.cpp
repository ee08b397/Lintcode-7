class Solution {
public:
    /**
     * @param A : An integer array
     * @return : Two integers
     */
    vector<int> singleNumberIII(vector<int> &A) {
        // write your code here
        int cnt = A[0];
        for (int i = 1; i < A.size(); i ++) {
            cnt ^= A[i];
        }
        int res = cnt & ~ (cnt - 1);
        int x = 0, y = 0;
        for (int i = 0; i < A.size(); i ++) {
            if (A[i] & res) x = x ^ A[i];
            else y = y ^ A[i];
        }
        vector<int> vec;
        vec.push_back(x);
        vec.push_back(y);
        return vec;
    }
};
