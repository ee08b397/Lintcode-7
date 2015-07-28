class Solution {
public:
    /**
     * @param s: A string 
     * @param p: A string includes "?" and "*"
     * @return: A boolean
     */
    bool isMatch(const char *s, const char *p) {
        //? match one
        //* match 0,1,2,3..
        // aaaabc *c true
        const char* star = nullptr;
        const char* rs = nullptr;
        
        while(*s) {
            if(*s == *p || *p == '?') { //match
                s++; p++;
                continue;
            }
            if(*p == '*') { 
                star = p; // record star
                p++; //match from next p
                rs = s; // record the position of s , star match 0
                continue;
            } 
            if(star != nullptr) { //if have star in front then backtrace
                p = star + 1; //reset the position of p 
                s = rs + 1; 
                rs ++; //star match 1,2,3,4,5....
                continue;
            }
            return false; //if not match return false
        }
        while(*p == '*') p++; //skip continue star
        return *p == '\0'; // successful match
    }
};
