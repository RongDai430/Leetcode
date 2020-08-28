/*
 * @lc app=leetcode.cn id=263 lang=cpp
 *
 * [263] 丑数
 */

// @lc code=start
class Solution {
public:
    bool isUgly(int num) {
        if(num == 0) return 0;
        vector<int> help = {2, 3, 5};
        bool flag = true;
        while(flag == true){
            flag = false;
            for(auto i : help){
                if(num % i == 0) {num /= i; flag = true; continue;}
            }
        }
        return num == 1;
    }
};

// @lc code=end

