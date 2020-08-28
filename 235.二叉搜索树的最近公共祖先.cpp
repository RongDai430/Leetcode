/*
 * @lc app=leetcode.cn id=235 lang=cpp
 *
 * [235] 二叉搜索树的最近公共祖先
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        //两种情况
        //分别在根的左右，则返回根
        //如果在根一侧，递归判断根的某一子树
        if(p-> val > q->val) swap(p, q);
        if(p->val <= root->val && q->val >= root->val) return root;
        if(p->val > root->val) return lowestCommonAncestor(root->right, p, q);
        return lowestCommonAncestor(root->left, p, q);
    }
};

// @lc code=end

