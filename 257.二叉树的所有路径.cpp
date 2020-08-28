/*
 * @lc app=leetcode.cn id=257 lang=cpp
 *
 * [257] 二叉树的所有路径
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
    vector<string> ans;
    vector<string> binaryTreePaths(TreeNode* root) {
        if(root == nullptr) return ans; 
        dfs(root, "");
        return ans;
    }
    void dfs(TreeNode* t, string s){
        //判断是否是叶子节点
        if(t->left == NULL && t->right == NULL) {ans.push_back(s + to_string(t->val)); return;}
        //左右子树遍历
        if(t->left != NULL) dfs(t->left, s + to_string(t->val) + "->");
        if(t->right != NULL) dfs(t->right, s + to_string(t->val) + "->");
    }
};

// @lc code=end

