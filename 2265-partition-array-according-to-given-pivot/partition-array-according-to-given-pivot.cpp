class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int>small;
        vector<int>equal;
        vector<int>large;

        for(int x:nums){
            if(x<pivot)
            small.push_back(x);

            else if(x==pivot)
            equal.push_back(x);

            else
            large.push_back(x);
        }

        vector<int>ans;

        for (int x : small)
            ans.push_back(x);

        for (int x : equal)
            ans.push_back(x);

        for (int x : large)
            ans.push_back(x);

        return ans;    

    }
};