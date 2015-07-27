#include <string>
#include <stack>

class Solution {
public:
    /**
     *@param n: Given a decimal number that is passed in as a string
     *@return: A string
     */
    string intTobin(long long res) {
        if (res == 0) return "0";
        stack<char> stk;
        while (res) {
            stk.push(res % 2 + '0');
            res = res / 2;
        }
        string str;
        while (!stk.empty()) {
            str += stk.top();
            stk.pop();
        }
        return str;
    }
    string doublestr(string str) {
        int d = 0;
        string st = str;
        for (int i = str.size() - 1; i >= 0; i --) {
            int temp = (str[i] - '0') * 2 + d;
            st[i] = temp % 10 + '0';
            d = temp / 10;
        }
        return st;
    }
    string solve(string str) {
        int index = str.size() - 1;
        while (index >= 0 && str[index] == '0') {
            index --;
        }
        if (index < 0) return "";
        return str.substr(0, index + 1);
    }
    string binaryRepresentation(string n) {
        // wirte your code here
        int pos = -1;
        long long res = 0;
        for (int i = 0; i < n.size(); i ++) {
            if (n[i] != '.') {
                res = res * 10 + n[i] - '0';
            } else {
                pos = i;
                break;
            }
        }
        string str = intTobin(res);
        if (pos == -1) return str;
        string str1 = n.substr(pos + 1, n.size() - pos - 1), str2 = str;
        if (str1.back() != '0' && str1.back() != '5') return "ERROR";
        else str2 += ".";
        if (solve(str1) == "") return str;
        int time = 0, maxt = str1.size() * 2;
        while (str1.size() > 0) {
            if (time >= maxt) return "ERROR";
            if (str1[0] >= '5') str2 += "1";
            else str2 += "0";
            str1 = solve(doublestr(str1));
            time ++;
        }
        return str2;
    }
};

