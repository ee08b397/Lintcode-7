class Solution {
    //param k : description of k
    //param numbers : array of numbers
    //return: description of return
    public int FindKth(ArrayList<Integer> num, int k, int start, int end) {
        if (end == start) return num.get(start);
        int temp = num.get(start);
        int left = start + 1, right = end;
        while (left <= right) {
            while (left <= right && num.get(left) < temp) left ++;
            while (left <= right && num.get(right) >= temp) right --;
            if (left < right) {
                int cnt = num.get(left);
                num.set(left, num.get(right));
                num.set(right, cnt);
                left ++;
                right --;
            }
        }
        num.set(start, num.get(right));
        num.set(right, temp);
        if (right - start + 1 == k) return num.get(right);
        else if(right - start + 1 < k) return FindKth(num, k - (right - start + 1), right + 1, end);
        else return FindKth(num, k, start, right - 1);
    }
    public int kthLargestElement(int k, ArrayList<Integer> numbers) {
        // write your code here
        return FindKth(numbers, numbers.size() - k + 1, 0, numbers.size() - 1);
    }
};
