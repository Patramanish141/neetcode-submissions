class Solution {
public:
    int findMin(vector<int> &nums) {
        int l = 0, r = nums.size()-1;

        int minVal = nums[0];
        while(l <= r){
            if(nums[l] < nums[r]){//already sorted
                minVal = min(minVal, nums[l]);
            }

            int mid = l + (r-l)/2;
            minVal = min(minVal, nums[mid]);

            if(nums[mid] >= nums[l]){
                l = mid+1;
            } else {
                r = mid-1;
            }
        }

        return minVal;
            
    }
};
