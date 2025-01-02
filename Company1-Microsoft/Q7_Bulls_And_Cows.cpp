// https://leetcode.com/problems/bulls-and-cows/
// Bulls and Cows


class Solution {
public:
    string getHint(string secret, string guess) {
        vector<int> count(10, 0);
        int x = 0, y = 0;
        for (int i = 0; i < secret.size(); i++) {
            if (secret[i] == guess[i]) x++;
            else count[secret[i] - '0']++;
        }

        for (int i = 0; i < secret.size(); i++) {
            if (secret[i] != guess[i] && count[guess[i] - '0'] > 0) {
                y++;
                count[guess[i] - '0']--;
            }
        }

        string result = "";
        result += to_string(x) + "A" + to_string(y) + "B";
        return result;
    }
};