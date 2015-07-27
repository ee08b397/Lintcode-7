class Solution {
public:
    /**
     *@param A: A list of integers
     *@param elem: An integer
     *@return: The new length after remove
     */
    int removeElement(vector<int> &A, int elem) {
        // write your code here
        int index = 0;
        for (int i = 0; i< A.size(); i++) {
            if (A[i] != elem) {
                A[index] = A[i];
                index ++;
            }
        }
        return index;
    }
};
