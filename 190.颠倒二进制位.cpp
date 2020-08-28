/*
 * @lc app=leetcode.cn id=190 lang=cpp
 *
 * [190] 颠倒二进制位
 */

// @lc code=start
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        //位运算
        //左移右移是一步操作
        //左移右移运算符优先级比+-低，比&高
        uint32_t ans = 0;
        for(int i = 0; i < 32; i++)
            ans = (ans << 1) + (n >> i & 1);
        return ans;
    }
};
// @lc code=end

