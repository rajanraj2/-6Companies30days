// https://leetcode.com/problems/longest-mountain-in-array/description/
// Longest Mountain in Array


class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int result = 0, n = arr.size();
        vector<int> pre(n, 0), suf(n + 1, 0);
        pre[0] = 0;

        for (int i = 1; i < n; i++) {
            if (arr[i] > arr[i - 1]) {
                pre[i] = pre[i - 1] + 1;
            }
            if (i > 1 && arr[n - i] > arr[n - i + 1]) suf[n - i] = suf[n - i + 1] + 1;
        }

        if (n > 1 && arr[0] > arr[1]) suf[0] = suf[1] + 1;
        for (int i = 0; i < n; i++) {
            if (pre[i] == 0 || suf[i] == 0) continue;
            result = max(result, pre[i] + suf[i] + 1);
        }
        return result;
    }
};