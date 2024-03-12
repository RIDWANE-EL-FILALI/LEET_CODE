class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
    {
        for(std::vector<int>::iterator it = nums2.begin(); it != nums2.end(); ++it)
            nums1.push_back(*it);
        std::sort(nums1.begin(), nums1.end());

        int totalSize = nums1.size();
        if (totalSize % 2 == 0)
            return static_cast<double>(nums1[totalSize / 2] + nums1[totalSize / 2 - 1]) / 2.0;
        else
            return static_cast<double>(nums1[totalSize / 2]);
    }
};
