/*
 * @lc app=leetcode.cn id=279 lang=cpp
 *
 * [279] 完全平方数
 */

// @lc code=start
class Solution {
public:
    int mysqrt(int x){
        return int(sqrt(x));
    }
    int numSquares(int n) {
        //动态规划
        //dp[n] = min(dp[x] + dp[n-x], dp[n]) x是小于n的所有平方数
        vector<int> memo(n+1, INT_MAX);

        for(int i = 1; i <= n; i++){
            if(mysqrt(i) * mysqrt(i) == i) memo[i] = 1;
            else{
                for(int j = 1; j <= mysqrt(i); j++)
                    memo[i] = min(memo[i], memo[i - j * j] + memo[j * j]);
            }
        }
        return memo[n];
    }
};

// @lc code=end

