// https://leetcode.com/problems/find-the-winner-of-the-circular-game/
// Find the Winner of the Circular Game


class Solution {
public:
    int findTheWinner(int n, int k) {
        int result = 0;
        for (int i = 1; i <= n; i++) {
            result = (result + k) % i;
        }
        return result + 1;
    }
};