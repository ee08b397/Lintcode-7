#include <vector>
#include <algorithm>

class Solution {
public:
    /**
     * @param S: A list of integers
     * @return: An integer
     */
    int triangleCount(vector<int> &S) {
        // write your code here
        int num = 0;
        sort(S.begin(), S.end());
        for (int i = S.size() - 1; i - 2 >= 0; i --) {
            int left = 0, right = i - 1;
            while (left < right) {
                if (S[i] >= S[left] + S[right]) left ++;
                else {
                    num += right - left;
                    right --;
                }
            }
        }
        return num;
    }
};