/*
 * @lc app=leetcode.cn id=258 lang=cpp
 *
 * [258] 各位相加
 */

// @lc code=start
class Solution {
public:
    int addDigits(int num) {
        //原数模9即为答案
        //需要特殊判断0和9
        if(num == 0) return 0;
        return num % 9 == 0 ? 9 : num % 9;
    }
};
// @lc code=end

