class Solution {
    vector<vector<int>> ans;
    void solve(int i, vector<int> &arr, vector<int>& candidates, int target){
        if(i==candidates.size()) return;
        if(target == 0){
            ans.push_back(arr);
            return;
        }
        if(target - candidates[i] >= 0) {
            arr.push_back(candidates[i]);
            solve(i, arr, candidates, target - candidates[i]);
            arr.pop_back();
        }
        solve(i+1, arr, candidates, target);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> arr;
        solve(0, arr, candidates, target);
        return ans;
    }
};
