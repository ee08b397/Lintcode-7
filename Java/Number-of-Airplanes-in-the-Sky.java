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
     * @param intervals: An interval array
     * @return: Count of airplanes are in the sky.
     */
    public class Node{
        int pos, vis;
        Node (int pos, int vis) {
            this.pos = pos;
            this.vis = vis;
        }
    }
    class mycmp implements Comparator<Node> {
        public int compare(Node x, Node y) {
            if (x.pos != y.pos) return x.pos - y.pos;
            else return x.vis - y.vis;
        }
    }
    public int countOfAirplanes(List<Interval> airplanes) {
        // write your code here
        ArrayList<Node> res = new ArrayList<Node>();
        for (int i = 0; i < airplanes.size(); i ++) {
            res.add(new Node(airplanes.get(i).start, 1));
            res.add(new Node(airplanes.get(i).end, 0));
        }
        Collections.sort(res, new mycmp());
        int count = 0, cur = 0;
        for (int i = 0; i < res.size(); i ++) {
            if (res.get(i).vis == 1) {
                cur ++;
                count = Math.max(count, cur);
            }
            else cur --;
        }
        return count;
    }
}
