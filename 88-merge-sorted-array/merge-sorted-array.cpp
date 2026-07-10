class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int j = 0;

        // fill nums2 elements after the first m valid elements
        for(int i = m; i < m + n; i++) {
            nums1[i] = nums2[j];
            j++;
        }

        sort(nums1.begin(), nums1.end());
    }
};