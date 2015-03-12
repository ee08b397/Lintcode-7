class Solution{
public:
    /**
     * @param colors: A list of integer
     * @param k: An integer
     * @return: nothing
     */
    void sortColors2(vector<int> &colors, int k) {
        // write your code here
        int left = 0, right = colors.size() - 1;
        for (int i = k; i >= 2; i --) {
            while (left < right) {
                while (left < right && colors[left] != i) {
                    left ++;
                }
                while (left < right && colors[right] == i) {
                    right --;
                }
                if (left < right) {
                    int cnt = colors[left];
                    colors[left] = colors[right];
                    colors[right] = cnt;
                }
                right = left - 1;
                left = 0;
            }
        }
    }
};
