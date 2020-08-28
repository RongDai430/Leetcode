/*
 * @lc app=leetcode.cn id=231 lang=cpp
 *
 * [231] 2的幂
 */

// @lc code=start
class Solution {
public:
    /*bool isPowerOfTwo(int n) {
        if(n == 1) return true;
        long long tmp = 1;
        for(int i = 1; i < n;i++){
            tmp *= 2;
            if(tmp == n) return true;
            if(tmp > n) return false;
        }
        return false;
    }*/
    bool isPowerOfTwo(int n) {
        //lowbit(x)函数返回x的二进制表达式中最低位的1所对应的值
        //lowbit(6) = lowbit(b110) = 4
        //lowbit(x) = x & (-x)
        if(n <= 0) return false;
        return lowbit(n) == n;
    }
    int lowbit(int x){
        return x & (-x);
    }
};


// @lc code=end

