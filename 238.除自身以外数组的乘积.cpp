/*
 * @lc app=leetcode.cn id=238 lang=cpp
 *
 * [238] 除自身以外数组的乘积
 */

// @lc code=start
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        //答案等于前缀乘积*后缀乘积
        //利用答案数组缓存前缀乘积
        vector<int> ans(nums.size(), 0);
        ans[0] = 1;
        for(int i = 1; i < nums.size(); i++) ans[i] = nums[i - 1] * ans[i - 1];
        int t = 1;
        for(int i = nums.size() - 2; i >= 0; i--){
            t = t * nums[i + 1];
            ans[i] = ans[i] * t;
        }
        return ans;
    }
};

// @lc code=end

