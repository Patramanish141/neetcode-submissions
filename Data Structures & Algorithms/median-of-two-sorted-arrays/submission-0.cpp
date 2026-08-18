class Solution {
public:
    vector<int> merge(vector<int>& nums1, vector<int>& nums2, int si, int mid, int ei){
        vector<int> temp;
        int i = si, j = 0;

        while(i <= mid && j<= ei){
            if(nums1[i] <= nums2[j]) temp.push_back(nums1[i++]);
            else temp.push_back(nums2[j++]);
        }
            
        while(i <= mid) temp.push_back(nums1[i++]);
        while(j <= ei) temp.push_back(nums2[j++]);

        return temp;
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> merged = merge(nums1, nums2, 0, nums1.size()-1, nums2.size()-1);//have a merged array of ascending order
        int n = merged.size();

        if(n % 2 == 0){
            int mid1 = merged[n/2];
            int mid2 = merged[n/2-1];

            return (double) (mid1+mid2)/2;
        } else {
            return (double) merged[n/2];
        }
        
        return 0.0;

    }
};
