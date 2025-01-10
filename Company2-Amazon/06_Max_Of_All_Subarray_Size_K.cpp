// https://www.geeksforgeeks.org/problems/maximum-of-all-subarrays-of-size-k3101/1
// K Sized Subarray Maximum


class Solution {
  public:
    // Function to find maximum of each subarray of size k.
    vector<int> maxOfSubarrays(vector<int>& arr, int k) {
        // code here
        vector<int> result;
        priority_queue<pair<int, int>> pq;
        
        for (int i = 0; i < arr.size(); i++) {
            pq.push({arr[i], i});
            while (pq.top().second <= i - k) pq.pop();
            
            if (i >= k - 1) result.push_back(pq.top().first);
        }
        return result;
    }
};


// Brute Force - TLE

// class Solution {
//   public:
//     // Function to find maximum of each subarray of size k.
//     vector<int> maxOfSubarrays(vector<int>& arr, int k) {
//         // code here
//         int n = arr.size();
//         vector<int> result(n - k + 1);
        
//         for (int i = 0; i <= n - k; i++) {
//             int val;
//             val = *max_element(arr.begin() + i, arr.begin() + i + k);
//             result[i] = val;
//         }
//         return result;
//     }
// };
