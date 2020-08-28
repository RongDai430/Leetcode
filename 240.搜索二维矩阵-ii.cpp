/*
 * @lc app=leetcode.cn id=240 lang=cpp
 *
 * [240] 搜索二维矩阵 II
 */

// @lc code=start
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        //O(m+n)的算法，很精妙
        //从右上方开始，不断往左下角搜索
        //如若比该数大，则排除该行
        //如若比该数小，则排除该列
        if(matrix.size() == 0) return false;
        int j = matrix[0].size() - 1;
        int i = 0;
        while(i < matrix.size() && j >= 0){
            if(matrix[i][j] == target) return true;
            if(matrix[i][j] > target) j--; else i++;
        }
        return false;
    }
};

// @lc code=end

