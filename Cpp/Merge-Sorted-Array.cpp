#include <vector>

class Solution {
public:
    /**
     * @param A and B: sorted integer array A and B.
     * @return: A new sorted integer array
     */
    vector<int> mergeSortedArray(vector<int> &A, vector<int> &B) {
        // write your code here
        vector<int> vec;
        int index1 = 0, index2 = 0, len1 = A.size(), len2 = B.size();
        while (index1 < len1 && index2 < len2) {
            if (A[index1] < B[index2]) {
                vec.push_back(A[index1]);
                index1++;
            } else {
                vec.push_back(B[index2]);
                index2++;
            }
        }
        while (index1 < len1) {
            vec.push_back(A[index1]);
            index1++;
        }
        while (index2 < len2) {
            vec.push_back(B[index2]);
            index2++;
        }
        return vec;
    }
};
