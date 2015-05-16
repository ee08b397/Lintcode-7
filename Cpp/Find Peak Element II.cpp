#include <vector>

class Solution {
public:
    /**
     * @param A: An integer matrix
     * @return: The index of the peak
     */
    vector<int> findPeakII(vector<vector<int> > A) {
        // write your code here
        vector<int> vec;
        int lenx = A.size(), leny = A[0].size();
        for (int i = 1; i < lenx - 1; i ++) {
            int left = 0, right = leny - 1, mid;
            while (left < right) {
                mid = left + (right - left) / 2;
                if (A[i][mid] > A[i][mid-1] && A[i][mid] > A[i][mid+1]) {
                    if (A[i][mid] > A[i-1][mid] && A[i][mid] > A[i+1][mid]) {
                        vec.push_back(i);
                        vec.push_back(mid);
                        return vec;
                    } else {
                        break;
                    }
                } else if (A[i][mid] < A[i][mid-1]) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
        }
    }
};

