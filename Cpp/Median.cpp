class Solution {
private:
   void swap(vector<int> &A, int i, int j)
   {
       int t = A[i];
       A[i] = A[j];
       A[j] = t;
   }
   int median(vector<int> &A, int start, int end, int k)
   {
       int i = start+1, j = end;
       while(i <= j) {
           while(i <= j && A[i] < A[start]) i++;
           while(i <= j && A[j] >= A[start]) j--;
           if (i < j) swap(A, i, j);
       }
       swap(A, start, j);
       if (j+1 == k) return A[j];
       else if (j+1 > k) return median(A, start, j, k);
       else return median(A, j+1, end, k);
   }

public:
    /**
     * @param nums: A list of integers.
     * @return: An integer denotes the middle number of the array.
     */
    int median(vector<int> &nums) {
        int n = nums.size();
        return median(nums, 0, n-1, n/2 + (n&1));
    }
};
