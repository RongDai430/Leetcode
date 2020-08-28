/*
 * @lc app=leetcode.cn id=213 lang=cpp
 *
 * [213] 打家劫舍 II
 */

// @lc code=start
class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==0) return 0;
        if(nums.size() == 1) return nums[0];
        //f[x]表示必选x的金额,且选了0号房间
        //g[x]表示不选x的金额
        vector<int> f(nums.size(), INT_MIN);
        vector<int> g(nums.size(), INT_MIN);
        f[0] = nums[0]; g[0] = 0;
        for(int i = 1; i < nums.size(); i++){
            f[i] = g[i-1] + nums[i];
            g[i] = max(f[i-1], g[i-1]);
        }
        int ans = max(f[nums.size()-2], g[nums.size()-2]);

        //f[x]表示必选x的金额，且不选0号房间
        //g[x]表示不选x的金额
        f = vector<int> (nums.size(), INT_MIN);
        g = vector<int> (nums.size(), INT_MIN);
        f[0] = INT_MIN;g[0] = 0;
        for(int i = 1; i <nums.size(); i++){
            f[i] = g[i-1] + nums[i];
            g[i] = max(f[i-1], g[i-1]);
        }
        ans = max(ans, max(f[nums.size()-1], g[nums.size()-1]));
        return ans;
    }
};
// @lc code=end

