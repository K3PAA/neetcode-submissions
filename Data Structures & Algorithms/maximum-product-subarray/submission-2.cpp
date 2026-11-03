class Solution {
public:
    int maxProduct(vector<int>& nums) {
        vector<int> minValues(nums.size(), 0), maxValues(nums.size(), 0);
        minValues[0] = nums[0];
        maxValues[0] = nums[0];

        int curr;
        for(int i = 1; i < nums.size(); ++i) {
            curr = nums[i];
            maxValues[i] = max(curr, max(maxValues[i - 1] * curr, minValues[i - 1] * curr) );
            minValues[i] = min(curr, min(minValues[i - 1] * curr, maxValues[i - 1] * curr) );
        }
        int maxVal = nums[0];
        for(int i = 1; i < nums.size(); ++i) {
            maxVal = max(maxVal, maxValues[i]);
        }
        return maxVal;
    }
};
