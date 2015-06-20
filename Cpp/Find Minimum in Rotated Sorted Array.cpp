class Solution {
public:
    /**
     * @param num: a rotated sorted array
     * @return: the minimum number in the array
     */
    int findMin(vector<int> &num) {
        // write your code here
        int len = num.size();
        int start = 0, end = len - 1, mid;
        while (start + 1 < end) {
            mid = start + (end - start) / 2;
            if (num[mid] < num[end]) end = mid;
            else start = mid;
        }
        if (num[start] < num[end]) return num[start];
        else return num[end];
    }
};
