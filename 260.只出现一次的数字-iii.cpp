/*
 * @lc app=leetcode.cn id=260 lang=cpp
 *
 * [260] 只出现一次的数字 III
 */

// @lc code=start
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        /*
        //该算法用了O(n)的空间复杂度
        unordered_set<int> s;
        for(int i = 0; i < nums.size(); i++){
            if(s.find(nums[i]) != s.end()) s.erase(nums[i]);
            else s.insert(nums[i]);
        }
        vector<int> ans;
        for(auto x : s) ans.push_back(x);
        return ans;*/

        //如果仅使用O(1)的空间复杂度
        //那么可以考虑位运算
        //考虑异或运算，相同的数异或为0
        //所有数异或以后，那么就是两个数ab的异或
        //考虑二进制，那么两个数的异或的二进制表达值为1
        //则表明，这两个数在这一位上不相同
        //那么这一位所有为1的数异或就是数a
        //这一位所有为0的数异或就是数b

        int ab = 0;
        for(auto x: nums) ab ^= x;
        int k = 0;
        while((ab>>k & 1) == 0) k++;
        return {getnum(nums, k, 1), getnum(nums, k, 0)};
    }

    int getnum(vector<int> &nums, int k, int t){
        int ans = 0;
        for(auto x : nums){
            if((x>>k & 1) == t) ans ^= x;
        }
        return ans;
    }

};

// @lc code=end

