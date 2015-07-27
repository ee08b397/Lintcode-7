#include <vector>

class Solution {
public:
    /**
     * @param A: a vector of integers
     * @return: an integer
     */
    int firstMissingPositive(vector<int> A) {
        // write your code here
        int index = 0, len = A.size();
        while (index < len) {
            if (A[index] >= 1 && A[index] <= len && A[index] != index + 1 && A[A[index]-1] != A[index]) {
                swap(A[index], A[A[index]-1]);
            } else index ++;
        }
        for (int i = 0; i < len; i ++) {
            if (A[i] != (i+1)) return i + 1;
        }
        return len + 1;
    }
};
