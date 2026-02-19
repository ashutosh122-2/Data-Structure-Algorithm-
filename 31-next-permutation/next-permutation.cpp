class Solution {
public:
    void nextPermutation(vector<int>& nums) {

        int n = nums.size();

        // Step 1: Find breakpoint
        int bp = -1;

        for(int i = n - 2; i >= 0; i--) {
            if(nums[i] < nums[i + 1]) {
                bp = i;
                break;
            }
        }

        // Step 2: If no breakpoint → reverse whole array
        if(bp == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }

        // Step 3: Find next greater element from right
        for(int i = n - 1; i > bp; i--) {
            if(nums[i] > nums[bp]) {
                swap(nums[i], nums[bp]);
                break;
            }
        }

        // Step 4: Reverse suffix ⭐
        reverse(nums.begin() + bp + 1, nums.end());
    }
};
