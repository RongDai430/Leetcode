/*
 * @lc app=leetcode.cn id=230 lang=cpp
 *
 * [230] 二叉搜索树中第K小的元素
 */

// @lc code=start
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
    vector<int> ans;
    int kthSmallest(TreeNode* root, int k) {
        helper(root,k);
        return ans[k-1];
    }
    void helper(TreeNode* root, int k){
        if(root == NULL) return;
        helper(root->left,k);
        ans.push_back(root->val);
        if(ans.size() >= k) return; //剪枝
        helper(root->right,k);
    }
};
// @lc code=end

