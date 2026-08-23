class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        
        int res = nums[0], currMin = 1, currMax = 1;

        for(int num : nums){
            int tmp = currMax * num;
            currMax = max(max(num * currMax, num * currMin), num);
            currMin = min(min(tmp, num * currMin), num);
            res = max(res, currMax);
        }

        return res;
    }
};
