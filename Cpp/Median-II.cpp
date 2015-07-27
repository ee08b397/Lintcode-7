class Solution {
public:
    /**
     * @param nums: A list of integers.
     * @return: The median of numbers
     */
    vector<int> medianII(vector<int> &nums) {
       priority_queue<int> maxHeap;
       priority_queue<int, vector<int>, greater<int>> minHeap;

       vector<int> ret;
       for(int i = 0; i < nums.size(); i++) {
            int tmp = nums[i];
            if (i & 1) {
                if (maxHeap.top() > tmp) {
                    maxHeap.push(tmp);
                    tmp = maxHeap.top();
                    maxHeap.pop();
                }
                minHeap.push(tmp);
            }
            else
            {
                if (minHeap.size() > 0 && minHeap.top() < tmp) {
                    minHeap.push(tmp);
                    tmp = minHeap.top();
                    minHeap.pop();
                }

                maxHeap.push(tmp);
            }

            ret.push_back(maxHeap.top());
       }


       return ret;
    }
};
