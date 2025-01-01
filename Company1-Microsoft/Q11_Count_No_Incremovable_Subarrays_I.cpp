// https://leetcode.com/problems/count-the-number-of-incremovable-subarrays-i/description/
// count the number of Incremovable Subarrays I


class Solution {
public:
    int incremovableSubarrayCount(vector<int>& nums) {
        int n = nums.size();
        int result = 0;

        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                bool isValid = true;

                for (int k = 1; k < i; k++) {
                    if (nums[k] <= nums[k - 1]) {
                        isValid = false;
                        break;
                    }
                }

                for (int k = j + 1; k < n - 1; k++) {
                    if (nums[k] >= nums[k + 1]) {
                        isValid = false;
                        break;
                    }
                }

                if (i > 0 && j < n - 1 && nums[i - 1] >= nums[j + 1]) isValid = false;
                if (isValid) result++;
            }
        }
        return result;
    }
};
