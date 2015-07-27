class Solution {
public:
    /**
     * @param A: Given an integers array A
     * @return: A long long array B and B[i]= A[0] * ... * A[i-1] * A[i+1] * ... * A[n-1]
     */
    vector<long long> productExcludeItself(vector<int> &nums) {
        // write your code here
        int n = nums.size();
        vector <long long> vec;
        if (nums.size() <= 1) return vec;
        vector<long long> vec1(n), vec2(n);
        vec1[0] = 1, vec2[n-1] = 1;
        for (int i = 1; i < n; i ++){
            vec1[i] = vec1[i-1] * nums[i-1];
        }
        for (int i = n-2; i >= 0; i --){
            vec2[i] = vec2[i+1] * nums[i+1];
        }
        for (int i = 0; i < n; i ++) {
            vec.push_back(vec1[i] * vec2[i]);
        }
        return vec;
    }
};
