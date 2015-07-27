#include <vector>
#include <algorithm>

class Solution {
public:
    /**
     * @param A: An integer array
     * @return: The number of element in the array that
     *          are smaller that the given integer
     */
    int findnum(vector<int> &A, int target) {
        lower_bound(A.begin(), A.end(), target) - A.begin();
    }
    vector<int> countOfSmallerNumber(vector<int> &A, vector<int> &queries) {
        // write your code here
        vector<int> vec;
        sort(A.begin(), A.end());
        for (int i = 0; i < queries.size(); i ++) {
            vec.push_back(findnum(A, queries[i]));
        }
        return vec;
    }
};
