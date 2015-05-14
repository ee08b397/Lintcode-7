#include <vector>

/**
 * Definition of Interval:
 */
classs Interval {
    int start, end;
    Interval(int start, int end) {
        this->start = start;
        this->end = end;
    }
};

class Solution {
public:
    /**
     * @param intervals: An interval array
     * @return: Count of airplanes are in the sky.
     */
    int countOfAirplanes(vector<Interval> &airplanes) {
        // write your code here
        vector<pair<int, bool> > v;
        for (auto &i : airplanes) {
            v.push_back(make_pair(i.start, true));
            v.push_back(make_pair(i.end, false));
        }
        int cnt = 0, res = 0;
        sort(v.begin(), v.end());
        for (auto &i : v) {
            if (i.second) cnt ++;
            else cnt --;
            res = max(res, cnt);
        }
        return res;
    }
};
