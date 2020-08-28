/*
 * @lc app=leetcode.cn id=264 lang=cpp
 *
 * [264] 丑数 II
 */

// @lc code=start
class Solution {
public:
    int nthUglyNumber(int n) {
        //设定三个指针分别代表2,3,5的倍乘数;
        //每次更新一个最小的丑数 min(un[c2]*2, un[c3]*3, un[c5]*5)
        //更新三个指针，如果丑数是ci*i，那么ci++
        //如果丑数是6，则c2和c3都需要处理，防止判重
        int c2 = 0, c3 = 0, c5 = 0;
        vector<int> un;
        un.push_back(1);
        for(int i = 1; i < n; i++){
            int minun = min(un[c2] * 2, min(un[c3] * 3, un[c5] * 5));
            if(minun == un[c2] * 2) c2++;
            if(minun == un[c3] * 3) c3++;
            if(minun == un[c5] * 5) c5++;
            un.push_back(minun);
        }
        return un[n-1];
    }
};

// @lc code=end

