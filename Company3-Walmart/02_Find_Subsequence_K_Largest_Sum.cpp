// https://leetcode.com/problems/find-subsequence-of-length-k-with-the-largest-sum/
// Find Subsequence of Length K with the Largest Sum


class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> result;
        int i = 0, t = k;
        while (t--) result.push_back(nums[i++]);

        for (int j = i; j < n; j++) {
            int mini = min_element(result.begin(), result.end()) - result.begin();
            if (result[mini] < nums[j]) {
                result.erase(result.begin() + mini);
                result.push_back(nums[j]);
            }
        }
        return result;
    }
};