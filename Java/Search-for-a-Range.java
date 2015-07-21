public class Solution {
    /**
     *@param A : an integer sorted array
     *@param target :  an integer to be inserted
     *return : a list of length 2, [index1, index2]
     */
    public int findleft(ArrayList<Integer> A, int target) {
        if (A == null || A.size() <= 0) return -1;
        int left = 0, right = A.size() - 1;
        while (left + 1 < right) {
            int mid = left + (right - left) / 2;
            if (A.get(mid) >= target) {
                right = mid;
            } else if (A.get(mid) < target) left = mid;
        }
        if (A.get(left) == target) return left;
        else if (A.get(right) == target) return right;
        return -1;
    }
    public int findRight(ArrayList<Integer> A, int target) {
        if (A == null || A.size() <= 0) return -1;
        int left = 0, right = A.size() - 1;
        while (left + 1 < right) {
            int mid = left + (right - left) / 2;
            if (A.get(mid) > target) {
                right = mid;
            } else if (A.get(mid) <= target) left = mid;
        }
        if (A.get(right) == target) return right;
        else if (A.get(left) == target) return left;
        return -1;
    }
    public ArrayList<Integer> searchRange(ArrayList<Integer> A, int target) {
        // write your code here
        ArrayList<Integer> res = new ArrayList<Integer>();
        res.add(findleft(A, target));
        res.add(findRight(A, target));
        return res;
    }
}

