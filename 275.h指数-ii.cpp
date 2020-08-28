/*
 * @lc app=leetcode.cn id=275 lang=cpp
 *
 * [275] H指数 II
 */

// @lc code=start
class Solution {
public:
    int hIndex(vector<int>& citations) {
        //与h指数1如法炮制
        //找到size()-i <= nums[i]的第一个数
        //[0,1,3,5,6]
        //[5,4,3,2,1]
        int ans = 0;
        for(int i = 0; i < citations.size(); i++){
            if(citations.size() - i <= citations[i]) {
                ans = citations.size() - i;
                break;
            }
        }
        return ans;
    }
};

// @lc code=end

