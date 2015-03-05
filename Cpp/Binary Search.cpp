class Solution {
public:
    /**
     * @param nums: The integer array.
     * @param target: Target number to find.
     * @return: The first position of target. Position starts from 0.
     */
    int binarySearch(vector<int> &array, int target) {
        // write your code here
        int left = 0, right = array.size() - 1, mid;
        while (left <= right) {
          mid = (left + right) / 2;
          if (array[mid] == target) {
            if(mid > 0 && array[mid - 1] == target) right = mid - 1;
            else return mid;
          }
          else if (array[mid] > target) {
            right = mid - 1;
          }
          else left = mid + 1;
        }
        return -1;
    }
};
