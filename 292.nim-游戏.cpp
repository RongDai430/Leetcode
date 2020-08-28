/*
 * @lc app=leetcode.cn id=292 lang=cpp
 *
 * [292] Nim 游戏
 */

// @lc code=start
class Solution {
public:
    bool canWinNim(int n) {
        //列举几个尝试数学归纳
        //1,2,3 5,6,7 true
        //4, 8 false
        return n % 4 != 0;
    }
};
// @lc code=end

