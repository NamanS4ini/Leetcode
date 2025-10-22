class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> merged;
        int idx1 = 0;
        int idx2 = 0;
        while(idx1 < nums1.size() && idx2 < nums2.size()){
            if(nums1[idx1] < nums2[idx2])
                merged.push_back(nums1[idx1++]);
            else
                merged.push_back(nums2[idx2++]);
        }
        while(idx1 < nums1.size())
            merged.push_back(nums1[idx1++]);
        while(idx2 < nums2.size())
            merged.push_back(nums2[idx2++]);
        if(merged.size() % 2 == 0)
        return double(merged[merged.size()/2] + merged[merged.size()/2 - 1])/2;
        return merged[merged.size()/2];
    }
};