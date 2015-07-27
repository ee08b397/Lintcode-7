class Solution {
public:
    /**
     * @param A: sorted integer array A which has m elements,
     *           but size of A is m+n
     * @param B: sorted integer array B which has n elements
     * @return: void
     */
    void mergeSortedArray(int A[], int m, int B[], int n) {
        // write your code here
        int *arr = new int[m+n];
        int index1 = 0, index2 = 0, index = 0;
        while (index1 < m && index2 < n) {
            if (A[index1] < B[index2]) {
                arr[index++] = A[index1++];
            } else {
                arr[index++] = B[index2++];
            }
        }
        while (index1 < m) {
            arr[index++] = A[index1++];
        }
        while (index2 < n) {
            arr[index++] =B[index2++];
        }
        index = 0;
        while (index < m + n) {
            A[index] = arr[index];
            index++;
        }
    }
};
