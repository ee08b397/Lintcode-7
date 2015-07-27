#include <vector>
#include <algorithm>
#include <iterator>

class Solution {
public:
    /**
     * @param nums: a vector of integers
     * @return: return nothing (void), do not return anything, modify nums in-place instead
     */
    void nextPermutation(vector<int> &nums) {
        // write your code here
        typedef vector<int>::iterator It;
        It first = nums.begin(), last = nums.end();
        if (first == last) return;
        It i = first;
        ++ i;
        if (i == last) return;
        i = last;
        -- i;
        for (;;) {
            It ii = i;
            -- i;
            if (*i < *ii) {
                It j = last;
                while (!(*i < *--j));
                iter_swap(i, j);
                reverse(ii, last);
                return;
            }
            if (i == first) {
                reverse(first, last);
                return;
            }
        }
    }
};
