/*
 * @lc app=leetcode.cn id=204 lang=cpp
 *
 * [204] 计数质数
 */

// @lc code=start
class Solution {
public:
    int countPrimes(int n) {
        //筛选素数的最优解法
        //对于2这个质数 赋值所有的2的倍数为非质数
        //查找下一个非质数，将其倍数设置为非质数
        vector<bool> flags(n);
        for(auto x : flags) x = true;

        for(int i = 2; i < sqrt(n); i++)
            if(flags[i])
                for(int j = i * i; j < n; j += i)
                    flags[j] = false;
        int ans = 0;
        for(int i = 2; i <= n; i++) if(flags[i] == true) ans++;
        return ans;
    }
};
// @lc code=end

