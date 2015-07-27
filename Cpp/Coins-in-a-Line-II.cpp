#include <vector>

class Solution {
public:
    /**
     * @param values: a vector of integers
     * @return: a boolean which equals to true if the first player will win
     */
    bool firstWillWin(vector<int> &values) {
        // write your code here
        int val1 = 0, val2 = 0;
        bool turn = true;
        for (int i = 0; i < values.size(); ) {
            int &val = turn ? val1 : val2;
            val += values[i++];
            if (i < values.size() && (i + 1 >= values.size() || values[i] >= values[i + 1])) {
                val += values[i++];
            }
            turn = !turn;
        }
        return val1 > val2;
    }
};