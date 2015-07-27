class Solution {
public:
    /**
     * @param pages: a vector of integers
     * @param k: an integer
     * @return: an integer
     */
    int copyBooks(vector<int> &pages, int k) {
        int n = pages.size();
        k = min(n, k);
        vector<int> sum_from_start(n, 0);
        partial_sum(pages.begin(), pages.end(), sum_from_start.begin());
        vector<vector<int> > minutes(k + 1, vector<int>(n, INT_MAX));
        for (int j = 0; j < n; j++) {
            minutes[1][j] = sum_from_start[j];
        }
        for (int i = 2; i <= k; i++) {
            minutes[i][0] = sum_from_start[1];
            int left = 0, right = 1;
            while (right < n) {
                int curr = sum_from_start[right] - sum_from_start[left];
                minutes[i][right] = min(max(curr, minutes[i - 1][left]), minutes[i][right]);
                if (left < right && minutes[i - 1][left] < curr) {
                    left++;
                }
                else {
                    right++;
                    // note: we should calculate the next solution starting from left - 1
                    if (left > 0) {
                        left--;
                    }
                }
            }
        }
        return minutes[k][n - 1];
    }
};