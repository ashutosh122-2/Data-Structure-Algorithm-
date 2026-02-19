class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n=nums.size();
        int start=0;
        int end=n-1;
        int mid=0;

        while(mid<=end){
            //ya to mid 0
            if(nums[mid]==0){
                swap(nums[mid],nums[start]);
                mid++;
                start++;
            }
            //ya to mid 1
            else if(nums[mid]==1){
                mid++;
            }
            //ya to mid 2
            else{
                swap(nums[mid],nums[end]);
                end--;
            }
        }
        
    }
};