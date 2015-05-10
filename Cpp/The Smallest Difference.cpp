#include <vector>
#include <algorithm>

class Solution {
public:
    /**
     * @param A, B: Two integer arrays.
     * @return: Their smallest difference.
     */
    int absdiff(int x, int y) {
        if (x - y > 0) return x - y;
        else return y - x;
    }
    int smallestDifference(vector<int> &A, vector<int> &B) {
        // write your code here
        sort(A.begin(), A.end());
        sort(B.begin(), B.end());
        int mindiff = absdiff(A[0], B[0]);
        int indexA = 0, indexB = 0, lenA = A.size(), lenB = B.size();
        while (indexA < lenA && indexB < lenB) {
            if (A[indexA] == B[indexB]) return 0;
            else if(A[indexA] < B[indexB]) {
                mindiff = min(mindiff, absdiff(A[indexA], B[indexB]));
                indexA ++;
            } else {
                mindiff = min(mindiff, absdiff(A[indexA], B[indexB]));
                indexB ++;
            }
        }
        return mindiff;
    }
};

