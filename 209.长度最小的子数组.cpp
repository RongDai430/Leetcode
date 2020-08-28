/*
 * @lc app=leetcode.cn id=209 lang=cpp
 *
 * [209] 长度最小的子数组
 */

// @lc code=start
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        //由于都是正整数，由这个限制联想到双指针算法
        //维护的区间，表示当前区间的值恰巧满足条件
        //控制右边界维持区间满足长度
        //由于都是正整数，所以是递增的
        int i = 0;
        int sum = 0;
        int ans = INT_MAX;
        for(int j = 0; j < nums.size(); j++){
            sum += nums[j];
            while(sum - nums[i] >= s){sum-=nums[i];i++;}
            if(sum >= s) ans = min(ans, j - i + 1);
        }
        return ans == INT_MAX ? 0 : ans;
    }
};
// @lc code=end

