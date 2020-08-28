/*
 * @lc app=leetcode.cn id=283 lang=cpp
 *
 * [283] 移动零
 */

// @lc code=start
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        //双指针
        //存储第一个不为0的下标
        int nz = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] != 0){
                nums[nz] = nums[i];
                nz++;
            }
        }
        for(int i = nz; i < nums.size(); i++)
            nums[i] = 0;
        return;
    }
};

// @lc code=end

