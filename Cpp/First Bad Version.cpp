/**
 * class VersionControl {
 *     public:
 *     static bool isBadVersion(int k);
 * }
 * you can use VersionControl::isBadVersion(k) to judge wether
 * the kth code version is bad or not.
*/
class Solution {
public:
    /**
     * @param n: An integers.
     * @return: An integer which is the first bad version.
     */
    int findFirstBadVersion(int n) {
        // write your code here
        if (n == 1) return 1;
        int left = 1, right = n, mid;
        while (left < right) {
            mid = left + (right - left) / 2;
            VersionControl res;
            if (res.isBadVersion(mid)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return right;
    }
};
