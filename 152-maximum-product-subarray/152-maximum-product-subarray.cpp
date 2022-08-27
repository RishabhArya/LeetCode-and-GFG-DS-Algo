class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int minEndingHere = nums[0], maxEndingHere = nums[0], maxOverall = nums[0];
        for(int i = 1; i< nums.size(); i++){
            int temp = maxEndingHere;
            maxEndingHere = 
                max({nums[i], nums[i] * maxEndingHere, nums[i] * minEndingHere});
            minEndingHere = 
                min({nums[i], nums[i] * temp, nums[i] * minEndingHere});
            maxOverall = max(maxOverall,maxEndingHere);
        }
        return maxOverall;
    }
};