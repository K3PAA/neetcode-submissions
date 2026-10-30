class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        if(nums.size() == 2) return max(nums[0], nums[1]);
        if(nums.size() == 3) return max(nums[2] + nums[0], nums[1]);
        vector<int> dp;
        dp.push_back(nums[0]);
        dp.push_back(nums[1]);
        dp.push_back(max(nums[0] + nums[2], nums[1]));
        for(int i = 3; i < nums.size(); ++i) {
            dp.push_back(nums[i] + max(dp[i - 2], dp[i - 3]));
        }
        return max(dp[nums.size() - 1], dp[nums.size() - 2]);
    }
};
