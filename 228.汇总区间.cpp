/*
 * @lc app=leetcode.cn id=228 lang=cpp
 *
 * [228] 汇总区间
 */

// @lc code=start
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        //双指针+long long类型判断是否连续
        vector<string> ans;
        int i = 0, j = 0;
        while(j < nums.size()){
           while(j + 1 < nums.size() && (long long) (nums[j + 1]) - (long long) (nums[j]) == 1) j++;
           if(i == j){
               ans.push_back(to_string(nums[i]));
           }
           else{
               ans.push_back(to_string(nums[i])+"->"+to_string(nums[j]));
           }
           i = j + 1;
           j = i;
        }
        return ans;
    }
};


// @lc code=end

