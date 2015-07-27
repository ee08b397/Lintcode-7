#include <vector>

class Solution {
public:
    /**
     * @param digits a number represented as an array of digits
     * @return the result
     */
    vector<int> plusOne(vector<int>& digits) {
        // Write your code here
        int d = 1;
        for (int i = digits.size() - 1; i >= 0; i --) {
            if (digits[i] + d >= 10) {
                int temp = digits[i] + d;
                d = temp / 10;
                digits[i] = temp % 10;
            } else {
                digits[i] += d;
                d = 0;
                break;
            }
        }
        vector<int> vec;
        if (d) vec.push_back(d);
        for (int i = 0; i < digits.size(); i ++) {
            vec.push_back(digits[i]);
        }
        return vec;
    }
};
