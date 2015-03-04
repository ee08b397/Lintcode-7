#include <vector>

class Solution {
public:
    /**
     * @param A: An integers array.
     * @return: return any of peek positions.
     */
    int findPeak(vector<int> A) {
        // write your code here
        int left = 0, right = A.size() - 1, mid;
        while (left < right) {
            mid = (left + right) / 2;
            if (A[mid] > A[mid-1] && A[mid] > A[mid+1]) return mid;
            else if(A[mid] < A[mid-1]) right = mid - 1;
            else left = mid + 1;
        }
    }
};

