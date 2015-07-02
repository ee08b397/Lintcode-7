/**
 * Definition of Interval:
 * public classs Interval {
 *     int start, end;
 *     Interval(int start, int end) {
 *         this.start = start;
 *         this.end = end;
 *     }
 */

class Solution {
    /**
     * Insert newInterval into intervals.
     * @param intervals: Sorted interval list.
     * @param newInterval: A new interval.
     * @return: A new sorted interval list.
     */
    public ArrayList<Interval> insert(ArrayList<Interval> intervals, Interval newInterval) {
        // write your code here
        ArrayList<Interval> result = new ArrayList<Interval>();
        int index = -1;
        for (int i = 0; i < intervals.size(); i ++) {
            if (intervals.get(i).start > newInterval.end) {
                result.add(newInterval);
                index = i;
                break;
            } else if (intervals.get(i).end < newInterval.start) {
                result.add(intervals.get(i));
            } else {
                newInterval.start = Math.min(newInterval.start, intervals.get(i).start);
                newInterval.end = Math.max(newInterval.end, intervals.get(i).end);
            }
        }
        if (index == -1) {
            result.add(newInterval);
            return result;
        }
        for (int i = index; i < intervals.size(); i ++) {
            result.add(intervals.get(i));
        }
        return result;
    }
}