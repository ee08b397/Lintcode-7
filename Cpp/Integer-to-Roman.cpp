class Solution {
public:
    /**
     * @param n The integer
     * @return Roman representation
     */
    string intToRoman(int n) {
        // Write your code here
        if(n <= 0) {
			return "";
		}
	    int nums[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
	    string symbols[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
	    string res;
	    int digit = 0;
	    while (n > 0) {
	    	int times = n / nums[digit];
	    	n -= nums[digit] * times;
	    	for ( ; times > 0; times --) {
	    		res += symbols[digit];
	    	}
	    	digit ++;
	    }
	    return res;
    }
};
