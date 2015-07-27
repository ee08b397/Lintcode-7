/**
 * Definition of Interval:
 * classs Interval {
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 */
class Solution {
public:
    /**
     * Insert newInterval into intervals.
     * @param intervals: Sorted interval list.
     * @param newInterval: new interval.
     * @return: A new interval list.
     */
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        // write your code here
        vector<Interval> vec;
        int res = intervals.size();
        for (int i = 0; i < intervals.size(); i ++) {
            if (intervals[i].end < newInterval.start) {
                vec.push_back(intervals[i]);
            } else if (intervals[i].start > newInterval.end) {
                res = i;
                break;
            } else {
                newInterval.start = min(newInterval.start, intervals[i].start);
                newInterval.end = max(newInterval.end, intervals[i].end);
            }
        }
        vec.push_back(newInterval);
        for (int i = res; i <intervals.size(); i++) {
            vec.push_back(intervals[i]);
        }
        return vec;
    }
};
