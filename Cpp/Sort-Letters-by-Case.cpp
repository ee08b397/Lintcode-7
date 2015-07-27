class Solution {
public:
    /**
     * @param chars: The letters array you should sort.
     */
    bool isupper(char ch) {
        if (ch >= 'a' && ch <= 'z') return false;
        else return true;
    }
    void sortLetters(string &letters) {
        // write your code here
        int left = 0, right = letters.size() - 1;
        while (left < right) {
            while (left < right && !isupper(letters[left])) {
                left ++;
            }
            while (left < right && isupper(letters[right])) {
                right --;
            }
            if (left < right) {
                char ch = letters[left];
                letters[left] = letters[right];
                letters[right] = ch;
            }
        }
    }
};
