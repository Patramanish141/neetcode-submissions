class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq(nums.begin(), nums.end());

        while(k-1>0){
            pq.pop();
            k--;
        }

        return pq.top();
    }
};