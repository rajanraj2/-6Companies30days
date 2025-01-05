// https://leetcode.com/problems/excel-sheet-column-title/description/
// Excel Sheet Column Title


class Solution {
public:
    string convertToTitle(int columnNumber) {
        string result = "";
        while (columnNumber > 0) {
            int rem = (columnNumber - 1) % 26;
            result.insert(result.begin(), ('A' + rem));
            columnNumber = (columnNumber - 1) / 26;
        }
        return result;
    }
};


// class Solution {
// public:
//     string convertToTitle(int columnNumber) {
//         string result = "";
//         int n = columnNumber;
        
//         while (n > 0) {
//             int rem = n % 26;
//             if (rem != 0) result.push_back('A' + (rem - 1));
//             else {
//                 result.push_back('Z');
//                 n -= 26;
//             }
//             n -= rem;
//             n /= 26;    
//         }

//         reverse(result.begin(), result.end());
//         return result;
//     }
// };