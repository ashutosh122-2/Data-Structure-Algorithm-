class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> copy=nums;
        for(int i=k;i<n+k;i++){
            nums[i%n]=copy[i-k];
        }
    }
};