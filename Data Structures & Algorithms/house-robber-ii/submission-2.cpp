class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        if(nums.size() == 2) return max(nums[0], nums[1]);
        if(nums.size() == 3) return max(nums[0], max(nums[1], nums[2]));

        vector<int> dom2;
        for(int i = 0; i < nums.size(); ++i) {
            dom2.push_back(nums[i]);
        }

        nums[2] += nums[0];
        for(int i = 3; i < nums.size() - 1; ++i) {
            nums[i] += max(nums[i - 2], nums[i - 3]);
        }

        dom2[3] += dom2[1];
        for(int i = 4; i < dom2.size(); ++i) {
            dom2[i] += max(dom2[i - 2], dom2[i - 3]);
        }

        return max(nums[nums.size() - 1],
            max(nums[nums.size()- 2], 
            max(dom2[dom2.size() - 1], 
            max(dom2[dom2.size()-2],
            nums[nums.size() - 3]))));
    }
};
