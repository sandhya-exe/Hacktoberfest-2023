// Intuition
// Use unordered_map as a dp map[TreeNode* root] is the maximum value that canbe robbed from the tree rooted at root

// Approach
// There are two situations: The thief rob the house at root r or he does not rob it
// Therefore dp[root] = max(dp[root->left] + dp[root->right], dp[root->left>left] + dp[root->left->right] + dp[root->right->left] + dp[root->right->right] + root->val) (If all of those nodes exists)

// If a root as no right subtree and left subtree, dp[root] = root->val

// Complexity
// Time complexity:
// O(n)



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
    unordered_map<TreeNode *, int> map;
    int rob(TreeNode* root) {
        traverse(root);
        return map[root];
    }
    void traverse(TreeNode* root){
        if(root == nullptr) return;
        if(root->left == nullptr && root->right == nullptr){
            map[root] = root->val;
            return;
        }
        int countRoot = 0;
        int xRoot = 0;
        if(root->left != nullptr && !map.count(root->left)){
            traverse(root->left);
            xRoot += map[root->left];
            if(root->left->left!=nullptr) countRoot += map[root->left->left];
            if(root->left->right!=nullptr) countRoot += map[root->left->right];
        }
        if(root->right != nullptr && !map.count(root->right)){
            traverse(root->right);
            xRoot += map[root->right];
            if(root->right->left!=nullptr) countRoot += map[root->right->left];
            if(root->right->right!=nullptr) countRoot += map[root->right->right];
        }
        map[root] = max(xRoot, countRoot+root->val);
    }
};
