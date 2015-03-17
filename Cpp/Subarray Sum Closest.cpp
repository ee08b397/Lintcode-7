// pre-processing: O(n)
// sort: O(nlogn)
// post-processing: O(n)
// total : O(nlogn)
// time: 2700 ms
class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: A list of integers includes the index of the first number
     *          and the index of the last number
     */
    vector<int> subarraySumClosest(vector<int> nums){
        // write your code here
        auto size = nums.size();

        if(size == 1) return {0,0};

        vector<pair<int,int>> f(size+1, make_pair(0,0));

        f[0].second = -1;

        for(auto i=0;i<size;++i)
        {
            f[i+1].first = f[i].first + nums[i];
            f[i+1].second = i;
        }

        std::sort(f.begin(), f.end());

        auto min_error = INT_MAX;

        auto start = -1;
        auto end = -1;

        for(auto i=1;i<=size;++i)
        {
            auto error = abs(f[i].first - f[i-1].first);
            if(error>=min_error) continue;
            min_error = error;

            start = min(f[i].second, f[i-1].second)+1;
            end = max(f[i].second, f[i-1].second);

        }

        return vector<int>{start, end};
    }
};
