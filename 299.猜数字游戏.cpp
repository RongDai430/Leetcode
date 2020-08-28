/*
 * @lc app=leetcode.cn id=299 lang=cpp
 *
 * [299] 猜数字游戏
 */

// @lc code=start
class Solution {
public:
    string getHint(string secret, string guess) {
        //简单模拟题
        unordered_map<int,int> record;
        string ans;
        int a = 0, b = 0;
        for(int i = 0; i < secret.size(); i++){
            record[secret[i]-'0']++;
            if(secret[i] == guess[i]) {
                b++;
            }
        }
        for(int i = 0; i < guess.size(); i++){
            if(record[guess[i] - '0'] > 0){
                a++;
                record[guess[i] - '0'] --;
            }
        }
        ans = to_string(b) + "A" + to_string(a - b) + "B";
        return ans;
    }
};

// @lc code=end

