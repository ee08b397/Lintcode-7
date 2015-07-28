class Solution {
public:
    /**
     * @param A an integer array
     * @param k an integer
     * @return an integer
     */
    void helper(vector<vector<int> > &dis, vector<int> &A) {
    	for (int i = 1; i <= A.size(); i ++) {
    		for (int j = i + 1; j <= A.size(); j ++) {
    			int mid = i + (j - i) / 2;
    			for (int k = i; k <= j; k ++) {
    				dis[i][j] += abs(A[k - 1] - A[mid - 1]);
    			}
    		}
    	}
    }
    int postOffice(vector<int>& A, int k) {
        // Write your code here
        if (A.empty() || k >= A.size()) return 0;
        sort(A.begin(), A.end());
        int len = A.size();
        vector<vector<int> > dis(len + 1, vector<int>(len + 1, 0));
        vector<vector<int> > dp(len + 1, vector<int>(k + 1, 0));
        helper(dis, A);
        for (int i = 0; i <= len; i ++) {
        	dp[i][1] = dis[1][i];
        }
        for (int nk = 2; nk <= k; nk ++) {
        	for (int i = nk; i <= len; i ++) {
        		dp[i][nk] = INT_MAX;
        		for (int j = 0; j < i; j ++) {
        			if(dp[i][nk] == INT_MAX || dp[j][nk - 1] + dis[j + 1][i] < dp[i][nk]) {
        				dp[i][nk] = dp[j][nk - 1] + dis[j + 1][i];
        			}
        		}
        	}
        }
        return dp[len][k];
    }
};
