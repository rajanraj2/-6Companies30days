// https://leetcode.com/problems/amount-of-time-for-binary-tree-to-be-infected/description/
// Amount of Time for Binary Tree to be Infected


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int amountOfTime(TreeNode* root, int start) {
        int maxDistance = 0;
        traverse(root, start, maxDistance);
        return maxDistance;
    }

    int traverse(TreeNode* root, int start, int& maxDistance) {
        int depth = 0;
        if (!root) return depth;

        int leftDepth = traverse(root->left, start, maxDistance);
        int rightDepth = traverse(root->right, start, maxDistance);

        if (root->val == start) {
            maxDistance = max(leftDepth, rightDepth);
            depth = -1;
        }
        else if (leftDepth >= 0 && rightDepth >= 0) {
            depth = max(leftDepth, rightDepth) + 1;
        }
        else {
            int distance = abs(leftDepth) + abs(rightDepth);
            maxDistance = max(maxDistance, distance);
            depth = min(leftDepth, rightDepth) - 1;
        }
        return depth;
    }
};