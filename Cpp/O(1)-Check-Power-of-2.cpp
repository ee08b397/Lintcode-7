class Solution {
public:
    /*
     * @param n: An integer
     * @return: True or false
     */
    bool checkPowerOf2(int n) {
        // write your code here
        long long cnt = n;
        return (cnt != 0) && ((cnt & (cnt - 1)) == 0);
    }
};
