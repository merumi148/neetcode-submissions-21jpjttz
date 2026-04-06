class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size() > nums2.size()) return findMedianSortedArrays(nums2, nums1);

        int m = nums1.size();
        int n = nums2.size();
        int low = 0, high = m;

        while (low <= high){
            int mid1 = (low + high) / 2;
            int mid2 = (m + n + 1) / 2 - mid1;

        int maxLeftX = (mid1 == 0) ? INT_MIN : nums1[mid1 - 1];
        int minRightX = (mid1 == m) ? INT_MAX : nums1[mid1];
        
        int maxLeftY = (mid2 == 0) ? INT_MIN : nums2[mid2 - 1];
        int minRightY = (mid2 == n) ? INT_MAX : nums2[mid2];
        
        if (maxLeftX <= minRightY && maxLeftY <= minRightX) {
            if ((m + n) % 2 == 0) {
                return (max((double)maxLeftX, (double)maxLeftY) + 
                        min((double)minRightX, (double)minRightY)) / 2.0;
            } else {
                return max((double)maxLeftX, (double)maxLeftY);
            }
        } else if (maxLeftX > minRightY) {
            high = mid1 - 1;
        } else {
            low = mid1 + 1;
        }
        }
        return 0.0;
    }
};
