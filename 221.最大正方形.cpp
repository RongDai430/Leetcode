/*
 * @lc app=leetcode.cn id=221 lang=cpp
 *
 * [221] 最大正方形
 */

// @lc code=start
class Solution {
private:
    int min3(int x,int y,int z){
        return min(x,min(y,z));
    }
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        //二维DP问题
        //dp[i][j]表示以[i][j]点为右下角所能围成的最大正方形
        //dp[i][j] = (dp[i][j] == 1)的情况下 min(dp[i-1][j],dp[i][j-1],dp[i-1][j-1]) + 1
        if(matrix.size() == 0) return 0;
        int ans = 0;
        vector<vector<int>> dp (matrix.size(), vector<int>(matrix[0].size(),0));
        for(int i = 0; i < matrix.size(); i++)
            for(int j = 0; j < matrix[0].size(); j++){
                if(i == 0 || j == 0) dp[i][j] = matrix[i][j] - '0';
                else{
                    if(matrix[i][j] == '0') dp[i][j] = 0;
                    else{
                        dp[i][j] = min3(dp[i-1][j], dp[i][j-1],dp[i-1][j-1]) + 1 ; 
                    }
                }
                ans = max(ans, dp[i][j]);
                //cout<<dp[i][j];
            }
        return ans * ans;
    }
};

// @lc code=end

