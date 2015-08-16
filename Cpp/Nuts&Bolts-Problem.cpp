/**
 * class Comparator {
 *     public:
 *      int cmp(string a, string b);
 * };
 * You can use compare.cmp(a, b) to compare nuts "a" and bolts "b",
 * if "a" is bigger than "b", it will return 1, else if they are equal,
 * it will return 0, else if "a" is smaller than "b", it will return -1.
 * When "a" is not a nut or "b" is not a bolt, it will return 2, which is not valid.
*/
class Solution {
public:
    /**
     * @param nuts: a vector of integers
     * @param bolts: a vector of integers
     * @param compare: a instance of Comparator
     * @return: nothing
     */
     void sortNutsAndBolts(vector<string> &nuts, 
                          vector<string> &bolts,
                          int s, int e, Comparator compare) {
        if(s >= e) return;
        
        int start = s, end = s, match;
        
        while(end <= e){
            if(compare.cmp(nuts[end], bolts[s])<=0){
                if(compare.cmp(nuts[end], bolts[s]) == 0)
                    match = start;
                swap(nuts[start], nuts[end]);
                start ++;
            }
            end ++;
        }
        swap(nuts[start-1], nuts[match]);
        int pivot = start - 1;
        
        start = s;
        end = s;
        while(end <= e) {
            if(compare.cmp(nuts[pivot], bolts[end])>=0) {
                if(compare.cmp(nuts[pivot], bolts[end]) == 0)
                    match = start;
                swap(bolts[start], bolts[end]);
                start ++;
            }
            end ++;
        }
        swap(bolts[pivot], bolts[match]);   
        
        sortNutsAndBolts(nuts, bolts, s, pivot-1, compare);
        sortNutsAndBolts(nuts, bolts, pivot+1, e, compare);
    }
    void sortNutsAndBolts(vector<string> &nuts, vector<string> &bolts, Comparator compare) {
        // write your code here
        sortNutsAndBolts(nuts, bolts, 0, bolts.size()-1, compare);
    }
};
