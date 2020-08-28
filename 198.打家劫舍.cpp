/*
 * @lc app=leetcode.cn id=198 lang=cpp
 *
 * [198] 打家劫舍
 */

// @lc code=start
class Solution {
public:
    int rob(vector<int>& nums) {
        //动态规划问题
        //需要两个状态
        //f[i]表示选前i个中，必选i
        //g[i]表示选前i个中，必不选i
        if(nums.size() == 0) return 0;
        vector<int> f(nums.size(), 0);
        vector<int> g(nums.size(), 0);
        f[0] = nums[0];
        for(int i = 1; i < nums.size(); i++){
            f[i] = g[i-1] + nums[i];
            g[i] = max(g[i-1], f[i-1]);
        }
        return max(f[nums.size() - 1], g[nums.size() - 1]);
    }
};
// @lc code=end

