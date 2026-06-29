class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int even = 0;
        int odd = 1;
        int n = nums.size();

        while (even < n && odd < n) {

            // Skip correctly placed even numbers
            while (even < n && nums[even] % 2 == 0)
                even += 2;

            // Skip correctly placed odd numbers
            while (odd < n && nums[odd] % 2 == 1)
                odd += 2;

            // Swap the misplaced pair
            if (even < n && odd < n)
                swap(nums[even], nums[odd]);
        }

        return nums;
    }
};