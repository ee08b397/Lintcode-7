#include <vector>

class Solution {
    /**
     * param A : an integer ratated sorted array
     * param target :  an integer to be searched
     * return : an integer
     */
public:
    int search(vector<int> &A, int target) {
        // write your code here
        if (A.empty()) return -1;
        int left = 0, right = A.size() - 1, mid;
        while (left <= right) {
            mid = left + (right - left) / 2;
            if (A[mid] == target) return mid;
            if (A[mid] < A[right]) {
                if (target > A[mid] && target <= A[right]) left = mid + 1;
                else right = mid - 1;
            } else if (A[mid] > A[left]) {
                if (target >= A[left] && target < A[mid]) right = mid - 1;
                else left = mid + 1;
            } else {
                left ++;
            }
        }
        return -1;
    }
};
