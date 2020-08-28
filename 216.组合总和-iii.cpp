/*
 * @lc app=leetcode.cn id=216 lang=cpp
 *
 * [216] 组合总和 III
 */

// @lc code=start
class Solution {
public:
    //回溯算法
    vector<vector<int>> ans;
    vector<int> cur;
    vector<vector<int>> combinationSum3(int k, int n) {
        dfs(k, n, 1);
        return ans;
    } 
    void dfs(int k, int sum, int start){
        if(k == 0 && sum == 0) {ans.push_back(cur); return;}
        if(sum < 0) return;
        for(int i = start; i <= 9; i++){
            cur.push_back(i);
            dfs(k - 1, sum - i, i + 1);
            cur.pop_back();
        }
        return;
    }
};
// @lc code=end

