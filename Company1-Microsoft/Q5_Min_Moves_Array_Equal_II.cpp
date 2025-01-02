// https://leetcode.com/problems/minimum-moves-to-equal-array-elements-ii/
// Minimum Moves to Equal Array Elements II


class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size(), result = 0;
        int val = nums[n / 2];
        for (int i = 0; i < n; i++) {
            result += abs(nums[i] - val);
        }
        return result;
    }
};


// class Solution {
// public:
//     int solve(vector<int>& nums, int n, int ind) {
//         int val = nums[ind];
//         int ans = 0;
//         for (int i = 0; i < nums.size(); i++) {
//             ans += (abs(nums[i] - val));
//         }
//         return ans;
//     }

//     int minMoves2(vector<int>& nums) {
//         sort(nums.begin(), nums.end());
//         int n = nums.size();
//         int result = 0;
//         if (n % 2) result = solve(nums, n, n / 2);
//         else {
//             result = min(solve(nums, n, (n - 1) / 2), solve(nums, n, n / 2));
//         }
//         return result;
//     }
// };


