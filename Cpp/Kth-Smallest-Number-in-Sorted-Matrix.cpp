#include <vector>
#include <queue>

class Solution {
public:
    /**
     * @param matrix: a matrix of integers
     * @param k: an integer
     * @return: the kth smallest number in the matrix
     */
    int kthSmallest(vector<vector<int> > &matrix, int k) {
        // write your code here
        priority_queue<pair<int, pair<int, int> >,vector<pair<int, pair<int, int> > >,
                       greater<pair<int, pair<int, int> > > > que;
        int lenx = matrix.size(), leny = matrix[0].size();
        for (int i = 0; i < leny; i ++) {
            que.push(make_pair(matrix[0][i], make_pair(0, i)));
        }
        int temp, cnt = 0;
        while (cnt < k) {
            pair<int, pair<int, int> > p = que.top();
            que.pop();
            temp = p.first;
            cnt ++;
            int x = p.second.first, y = p.second.second;
            if (x + 1 < lenx) {
                que.push(make_pair(matrix[x+1][y], make_pair(x + 1, y)));
            }
        }
        return temp;
    }
};
