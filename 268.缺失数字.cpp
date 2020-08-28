/*
 * @lc app=leetcode.cn id=268 lang=cpp
 *
 * [268] 缺失数字
 */

// @lc code=start
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum = (nums.size() + 1) * nums.size() / 2;
        for(auto x : nums){
            sum -= x;
        }
        return sum;
    }
};
// @lc code=end

