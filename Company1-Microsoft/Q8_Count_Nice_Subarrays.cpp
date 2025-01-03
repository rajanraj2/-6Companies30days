// https://leetcode.com/problems/count-number-of-nice-subarrays/
// Count Number of Nice Subarrays


class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> arr(n + 1, 0);
        int result = 0, odd = 0;
        arr[0] = 1;
        for (int it : nums) {
            odd += (it % 2);
            if (odd - k >= 0) result += arr[odd - k];
            arr[odd]++;
        }
        return result;
    }
};