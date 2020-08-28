/*
 * @lc app=leetcode.cn id=304 lang=cpp
 *
 * [304] 二维区域和检索 - 矩阵不可变
 */

// @lc code=start
class NumMatrix {
    /*
    如何求得sum矩阵
    step1. 先从左往右累加
    step2. 从上往下累加
    0 0 0 0      0 0  0  0      0 0   0   0
    0 3 0 1      0 3  3  4      0 3   3   4
    0 5 6 3  --> 0 5 11 14  --> 0 8  14  18
    0 1 2 0      0 1  3  3      0 9  17  21
    //未补零时：
    sum(r1,c1,r2,c2) = sum[r2,c2] - sum[r1-1,c2] - sum[r2,c1-1] + sum[r1-1,c1-1]
    //补零以后：
    sum(r1,c1,r2,c2) = sum[r2+1,c2+1] - sum[r1,c2+1] - sum[r2+1,c1] + sum[r1,c1]
    */
public:
    vector<vector<int>> sum;

    NumMatrix(vector<vector<int>>& matrix) {
        if(matrix.size() == 0 || matrix[0].size() == 0) return;

        sum = vector<vector<int>> (matrix.size() + 1, vector<int>(matrix[0].size() + 1, 0));

        for(int i = 1; i <= matrix.size(); i++)
            for(int j = 1; j <= matrix[0].size(); j++)
                sum[i][j] = sum[i][j-1] + matrix[i-1][j-1];

        for(int j = 1; j <= matrix[0].size(); j++)
            for(int i = 1; i <= matrix.size(); i++)
                sum[i][j] += sum[i-1][j];
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        return sum[row2+1][col2+1] - sum[row1][col2 +1] - sum[row2+1][col1] + sum[row1][col1];
    }
};


/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
// @lc code=end

