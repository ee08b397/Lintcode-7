#include <vector>

class Solution {
public:
	/**
	 * @param A: Array of integers.
	 * return: The single number.
	 */
    int singleNumber(vector<int> &A) {
        // write your code here
        if (A.size() == 0) return 0;
        int res = A[0];
        for(int i = 1; i < A.size(); i++){
            res = res ^ A[i];
        }
        return res;
    }
};

