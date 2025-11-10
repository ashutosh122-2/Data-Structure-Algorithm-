class Solution {
public:
    void getpermu(vector<int>& arr , int idx , vector<vector<int>>&ans){
        if(idx==arr.size()){
            ans.push_back({arr});
            return;
        }

        for(int i=idx;i<arr.size();i++){
            swap(arr[idx],arr[i]);
            getpermu(arr,idx+1,ans);
            swap(arr[idx],arr[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& arr) {
        vector<vector<int>> ans;
        getpermu(arr,0,ans);
        return ans;
        
    }
};