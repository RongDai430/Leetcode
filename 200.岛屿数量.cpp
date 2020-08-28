/*
 * @lc app=leetcode.cn id=200 lang=cpp
 *
 * [200] 岛屿数量
 */

// @lc code=start
class Solution {
public:
    //DFS
    int dx[4] = {0, -1, 0, 1};
    int dy[4] = {-1, 0, 1, 0};

    void dfs(int x, int y, vector<vector<char>>& grid){
        //当前岛屿设置为不可接触
        grid[x][y] = '0';
        for(int k = 0; k < 4; k++){
            int dxx = dx[k] + x;
            int dyy = dy[k] + y;
            if(dxx < 0 || dxx >= grid.size() || dyy < 0 || dyy >= grid[0].size())
                continue;
            if(grid[dxx][dyy] == '0') continue;
            dfs(dxx, dyy, grid);
        }
        return;
    }

    int numIslands(vector<vector<char>>& grid) {
        if(grid.size() == 0 || grid[0].size() == 0) return 0;
        int ans = 0;
        for(int i = 0; i < grid.size(); i++)
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == '1'){
                    ans++;
                    dfs(i, j, grid);
                }
            }
        return ans;
    }
};

// @lc code=end

