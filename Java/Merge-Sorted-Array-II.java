class Solution {
    /**
     * @param A and B: sorted integer array A and B.
     * @return: A new sorted integer array
     */
    public ArrayList<Integer> mergeSortedArray(ArrayList<Integer> A, ArrayList<Integer> B) {
        int len = B.size();
        for (int i = 0; i < len; ++i) 
            A.add(B.get(i));
        Collections.sort(A);
        return A;
    }
}