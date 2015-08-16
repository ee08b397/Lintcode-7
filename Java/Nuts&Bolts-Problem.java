public class Solution {
    /**
     * @param nuts: an array of integers
     * @param bolts: an array of integers
     * @param compare: a instance of Comparator
     * @return: nothing
     */
    public void quick_sortNutsAndBolts(String[] nuts, String[] bolts, int s, int e, NBComparator compare) {
        if (s >= e) return;
        int start = s, end = s, match = 0;
        while (end <= e) {
            if (compare.cmp(nuts[end], bolts[s]) <= 0) {
                if (compare.cmp(nuts[end], bolts[s]) == 0) {
                    match = start;
                }
                //swap(nuts[start], nuts[end]);
                start ++;
            }
            end ++;
        }
        //swap(nuts[start - 1], nuts[match]);
        int pivot = start - 1;
        start = s;
        end = s;
        while (end <= e) {
            if (compare.cmp(nuts[pivot], bolts[end]) >= 0) {
                if (compare.cmp(bolts[end], nuts[pivot]) == 0) {
                    match = start;
                }
                //swap(bolts[end], bolts[start]);
                start ++;
            }
            end ++;
        }
        //swap(bolts[pivot], bolts[match]);
        quick_sortNutsAndBolts(nuts, bolts, s, pivot - 1, compare);
        quick_sortNutsAndBolts(nuts, bolts, pivot + 1, e, compare);
    }
    public void sortNutsAndBolts(String[] nuts, String[] bolts, NBComparator compare) {
        // write your code here
        quick_sortNutsAndBolts(nuts, bolts, 0, nuts.length - 1, compare);
    }
};