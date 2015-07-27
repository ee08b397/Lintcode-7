class Solution {
public:
    /**
     * @param A an integer array
     * @return a long integer
     */
     long long factor(long long n) {
        if (n <= 1) return 1;
        long long res = 1;
        for (long long i = 2; i <= n; i ++) {
            res *= i;
        }
        return res;
    }
    int findrank(vector<int> &dup, set<int> &hash, int num) {
    	int cur = 0;
    	for (int i = 0; i < dup.size(); i ++) {
            if (dup[i] == num) return cur;
            else if (hash.find(dup[i]) == hash.end()) cur ++;
        }
        return cur;
    }
    long long permutationIndex(vector<int>& A) {
        // Write your code here
        int len = A.size();
        vector<int> dup(len);
        for (int i = 0; i < len; i ++) {
            dup[i] = A[i];
        }
        sort(dup.begin(), dup.end());
        set<int> hash;
        long long res = 1;
        for (int i = 0; i < len; i ++) {
        	int rank = findrank(dup, hash, A[i]);
        	res = res + rank * factor(len - i - 1);
            hash.insert(A[i]);
        }
        return res;
    }
};

