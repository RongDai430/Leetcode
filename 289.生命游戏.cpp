/*
 * @lc app=leetcode.cn id=289 lang=cpp
 *
 * [289] 生命游戏
 */

// @lc code=start
class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        //要求使用原地算法
        //因为状态只有0和1
        //考虑用低位表示原始状态
        //用高位表示新的状态
        //存活 |= 0b10 死亡 |= 0b00
        int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
        int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
        for(int i = 0; i < board.size(); i++)
            for(int j = 0; j < board[0].size(); j++){
                int cnt = 0;
                for(int k = 0; k < 8; k++){
                    int tx = i + dx[k], ty = j + dy[k];
                    if(tx < 0 || tx >= board.size() || ty < 0 || ty >= board[0].size())
                        continue;
                    cnt += board[tx][ty] & 0b01;    //低位判断原状态
                }
                if(board[i][j] & 0b01 == 1) {   //原状态为活
                    if(cnt < 2) board[i][j] |= 0b00;
                    else if(cnt == 2 || cnt == 3) board[i][j] |= 0b10;
                    else board[i][j] |= 0b00;
                }
                else{
                    if(cnt == 3) board[i][j] |= 0b10;
                }
            }

        for(int i = 0; i < board.size(); i++)
            for(int j = 0; j < board[0].size(); j++)
                board[i][j] >>= 1;  //右移
    }
};
// @lc code=end

