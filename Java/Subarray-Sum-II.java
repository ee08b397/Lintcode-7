public class Solution {
    /**
     * @param A an integer array
     * @param start an integer
     * @param end an integer
     * @return the number of possible answer
     */
    public int subarraySumII(int[] A, int start, int end) {
        int n = 0;
        int[] B = new int[A.length];
        B[0] = A[0];
        for(int i = 1; i < A.length; i++){
            B[i] = B[i-1]+A[i];
        }
        for(int i = 0; i < B.length; i++){
            if(B[i] >= start && B[i] <= end){
                n++;
            }
            for(int j = 0; j < i; j++){
                if((B[i]-B[j] >= start) && (B[i]-B[j] <= end)){
                    n++;
                }
            }
        }
        return n;
    }
}
