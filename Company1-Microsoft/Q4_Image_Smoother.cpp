// https://leetcode.com/problems/image-smoother/description/
// Image Smoother


class Solution {
public:
    pair<int, int> helper(int i, int j, int n, int m, vector<vector<int>>& img) {
        if (i < 0 || i >= n || j < 0 || j >= m) return {0, 0};
        int sum = img[i][j];
        int count = 1;
        if (j < m - 1 ) {
            sum += img[i][j + 1];
            count++;
        }
        if (j > 0) {
            sum += img[i][j - 1];
            count++;
        }
        return {sum, count};
    }

    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int n = img.size(), m = img[0].size();
        vector<vector<int>> grid(n, vector<int>(m));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                auto val1 = helper(i - 1, j, n, m, img);
                auto val2 = helper(i, j, n, m, img);
                auto val3 = helper(i + 1, j, n, m, img);
                int sum = (val1.first + val2.first + val3.first);
                int count = (val1.second + val2.second + val3.second);
                grid[i][j] = sum / count;
            }
        }
        return grid;
    }
};