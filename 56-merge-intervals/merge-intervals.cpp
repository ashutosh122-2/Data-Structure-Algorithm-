class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // Handle edge case where the intervals list is empty
        if(intervals.empty()) return {};
        
        // Sort so that we can easily identify if there are any overlaps
        sort(intervals.begin(), intervals.end());
        
        vector<vector<int>> ans;
        ans.push_back(intervals[0]);
        
        for(int i = 1 ; i < intervals.size(); i++){
            // To find if there is any overlap:
            // if (currentFirst <= mergedLast) then merge
            if(intervals[i][0] <= ans.back()[1]){
                ans.back()[1] = max(ans.back()[1], intervals[i][1]);
            }
            else{
                // No overlap, add as a new interval
                ans.push_back(intervals[i]);
            }
        }
        
        return ans;
    }
};