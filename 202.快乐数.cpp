/*
 * @lc app=leetcode.cn id=202 lang=cpp
 *
 * [202] 快乐数
 */

// @lc code=start
class Solution {
public:
    bool isHappy(int n) {
        set<int> helper;
        while(true){
            int x = 0;
            while(n){
                x += (n % 10) * (n % 10);
                n /= 10;
            }
            if(x == 1) return true;
            if(helper.find(x) != helper.end()) return false;
            helper.insert(x);
            n = x;
        }
    }
};
// @lc code=end

