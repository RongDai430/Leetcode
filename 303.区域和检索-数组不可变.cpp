/*
 * @lc app=leetcode.cn id=303 lang=cpp
 *
 * [303] 区域和检索 - 数组不可变
 */

// @lc code=start
class NumArray {
public:
    //前缀和
    vector<int> mysum;

    NumArray(vector<int>& nums) {
        mysum = vector<int>(nums.size() + 1, 0);
        int sum = 0;
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
            mysum[i + 1] = sum;
        }
    }

    int sumRange(int i, int j) {
        return mysum[j + 1] - mysum[i]; 
    }
};


/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */
// @lc code=end

