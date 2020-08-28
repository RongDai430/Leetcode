/*
 * @lc app=leetcode.cn id=297 lang=cpp
 *
 * [297] 二叉树的序列化与反序列化
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
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        //Encode in 12##34##5##
        //考虑到数字不一定只有一位
        //需要编码为1,2,#,#,3,4,#,#,5,#,#
        string ans = "";
        helps(root, ans);
        return ans;
    }

    void helps(TreeNode* temp, string &s){
        if(temp == NULL) {s += "#,"; return;}
        s += to_string(temp->val) + ",";
        helps(temp->left , s);
        helps(temp->right, s);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int index = 0;
        return helpd(data, index);
    }

    TreeNode* helpd(string &data, int &index){
        //index表示当前遍历到的string的下标
        if(data[index] == '#'){
            index += 2;
            return nullptr;
        }
        int t = index;
        while(data[t] != ',') t++;
        string num = data.substr(index, t - index);
        TreeNode * r = new TreeNode(stoi(num));

        index = t + 1;
        r->left = helpd(data, index);
        r->right = helpd(data, index);
        return r;
    }
};


// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
// @lc code=end

