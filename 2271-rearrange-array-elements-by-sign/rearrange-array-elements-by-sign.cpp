class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums)
    {
        vector<int> pos;
        vector<int> neg;

        // Separate positive & negative
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] < 0)
                neg.push_back(nums[i]);
            else
                pos.push_back(nums[i]);
        }

        int i = 0, j = 0, k = 0;

        // Alternate merge (IMPORTANT FIX)
        while(i < pos.size() && j < neg.size()) {
            nums[k++] = pos[i++];
            nums[k++] = neg[j++];
        }

        // Remaining elements (safe)
        while(i < pos.size())
            nums[k++] = pos[i++];

        while(j < neg.size())
            nums[k++] = neg[j++];

        return nums;   // ⭐ REQUIRED
    }
};
