// https://leetcode.com/problems/maximum-sum-of-distinct-subarrays-with-length-k/description/
// Maximum Sum of Distinct Subarrays (with length k)


class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        long long sum = 0, result = 0;
        int left = 0;
        unordered_set<int> st;

        for (int right = 0; right < n; right++) {
            if (st.find(nums[right]) == st.end()) {
                sum += nums[right];
                st.insert(nums[right]);

                if (right - left + 1 == k) {
                    result = max(result, sum);
                    sum -= nums[left];
                    st.erase(nums[left]);
                    left++;
                }
            }

            else {
                while (nums[left] != nums[right]) {
                    sum -= nums[left];
                    st.erase(nums[left]);
                    left++;
                }
                left++;
            }
        }
        
        return result;
    }
};