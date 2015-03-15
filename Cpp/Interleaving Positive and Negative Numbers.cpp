class Solution {
public:
    /**
     * @param A: An integer array.
     * @return an integer array
     */
    vector<int> rerange(vector<int> &A) {
        // write your code here
        int left = 0, right = A.size() - 1, pos = 0, neg = 0;
        while (left < right) {
            while (A[left] > 0 && left < right) {
                left ++;
                pos ++;
            }
            while (A[right] < 0 && left < right) {
                right --;
            }
            if (left < right) {
                int cnt = A[left];
                A[left] = A[right];
                A[right] = cnt;
            }
        }
        left = 0;
        right = A.size() - 1;
        if (pos < A.size() - pos) {
            right --;
        } else if (pos > A.size() - pos) {
            left ++;
        }
        while (left < right) {
            int cnt = A[left];
            A[left] = A[right];
            A[right] = cnt;
            left += 2;
            right -= 2;
        }
        return A;
    }
};
