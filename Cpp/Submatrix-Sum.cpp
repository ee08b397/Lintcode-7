#include <vector>
#include <map>

class Solution {
public:
    /**
     * @param matrix an integer matrix
     * @return the coordinate of the left-up and right-down number
     */
    vector<vector<int> > submatrixSum(vector<vector<int> >& matrix) {
        // Write your code here
        vector<vector<int> > res;
        if (matrix.empty() || matrix[0].empty()) return res;
        int lenx = matrix.size(), leny = matrix[0].size();
        vector<vector<vector<int> > > s(leny, vector<vector<int> >(lenx, vector<int>(lenx)));
        for (int i = 0; i < leny; i ++) {
            vector<int> temp(lenx);
            temp[0] = matrix[0][i];
            for (int j = 1; j < lenx; j ++) {
                temp[j] = temp[j - 1] + matrix[j][i];
            }
            for (int j = 0; j < lenx; j ++) {
                for (int k = j; k < lenx; k ++) {
                    s[i][j][k] = temp[k] - temp[j] + matrix[j][i];
                }
            }
        }
        for (int i = 0; i < lenx; i ++) {
            for (int j = i; j < lenx; j ++) {
                map<int, int> hash;
                hash[0] = -1;
                int sum = 0;
                for (int k = 0; k < leny; k ++) {
                    sum += s[k][i][j];
                    if (hash.find(sum) == hash.end()) {
                        hash[sum] = k;
                    } else {
                        vector<int> vec1, vec2;
                        vec1.push_back(i);
                        vec1.push_back(hash[sum]+1);
                        vec2.push_back(j);
                        vec2.push_back(k);
                        res.push_back(vec1);
                        res.push_back(vec2);
                        return res;
                    }
                }
            }
        }
        return res;
    }
};
