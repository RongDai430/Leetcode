/*
 * @lc app=leetcode.cn id=229 lang=cpp
 *
 * [229] 求众数 II
 */

// @lc code=start
class Solution {
public:
    //摩尔投票算法
    //线性时间和常数空间的算法
    //寻找严格大于(n/k)的数
    //1.建立k-1个仓库，并初始化计数值
    //2.遍历存储数据，如果与仓库存的数相同，则计数++
    //3.如果有仓库为空，存储在仓库
    //4.如果与所有仓库值都不一样，则所有仓库的计数--
    //**即一共消耗了k个数，那么必然会剩下出现大于n/k的数
    //5.遍历确定答案

    vector<int> majorityElement(vector<int>& nums) {
        int n1, n2, c1 = 0, c2 = 0;
        for(int i = 0; i < nums.size(); i++){
            if(n1 == nums[i]) c1++;
            else if(n2 == nums[i]) c2++;
            else if (c1 == 0) {n1 = nums[i]; ++c1;}
            else if (c2 == 0) {n2 = nums[i]; ++c2;}
            else {--c1; --c2;}
        }

        int count1 = 0, count2 = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == n1) count1++;
            else if(nums[i] == n2) count2++;
        }

        vector<int> ans;
        if(count1 > nums.size() / 3) ans.push_back(n1);
        if(count2 > nums.size() / 3) ans.push_back(n2);
        return ans;
    }
};

// @lc code=end

